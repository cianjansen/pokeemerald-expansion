Ouderkerk_MapScripts::
	.byte 0

@ Thin per-map entry points: set VAR_0x8008 to this map's own bike-blocker
@ NPC local_id, then hand off to the shared Common_EventScript_BikeBlocker*
@ logic below. Add one matching pair of these per map that has a bike
@ blocker (see OuderkerAmstel/scripts.inc for another example) instead of
@ hardcoding a local_id in the shared scripts themselves — that hardcoding
@ is exactly the LOCALID_PLAYERS_HOUSE_2F_MOM bug from spec.md's map-cloning
@ checklist, just pre-empted here instead of hit later.
Ouderkerk_EventScript_FietsBlokkerTalk::
	setvar VAR_0x8008, LOCALID_OUDERKERK_FIETS_BLOKKER
	goto Common_EventScript_BikeBlockerTalk
	end

Ouderkerk_EventScript_FietsBlokkerTrigger::
	setvar VAR_0x8008, LOCALID_OUDERKERK_FIETS_BLOKKER
	goto Common_EventScript_BikeBlockerTrigger
	end

Common_EventScript_BikeBlockerTalk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FATBIKE, Common_EventScript_BikeBlockerTalk_Done
	call Common_EventScript_BikeBlockerDialog
	release
	end

Common_EventScript_BikeBlockerTalk_Done::
	msgbox Ouderkerk_Text_FietsBlokkerSuccess, MSGBOX_DEFAULT
	release
	end

Common_EventScript_BikeBlockerTrigger::
	lockall
	goto_if_set FLAG_GOT_FATBIKE, Common_EventScript_BikeBlockerTrigger_Done
	applymovement VAR_0x8008, Common_Movement_FaceUp
	waitmovement 0
	call Common_EventScript_BikeBlockerDialog
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_PushPlayerBackSouth
	waitmovement 0
	releaseall
	end

Common_EventScript_BikeBlockerTrigger_Done::
	releaseall
	end

@ Shared dialog: shows the first-time or repeat message depending on
@ FLAG_TALKED_TO_FIETS_BLOKKER. Caller is responsible for lock/faceplayer
@ and closing/releasing afterward. Must be entered via `call`.
Common_EventScript_BikeBlockerDialog::
	goto_if_set FLAG_TALKED_TO_FIETS_BLOKKER, Common_EventScript_BikeBlockerDialog_Repeat
	msgbox Ouderkerk_Text_FietsBlokkerFirst, MSGBOX_DEFAULT
	setflag FLAG_TALKED_TO_FIETS_BLOKKER
	return

Common_EventScript_BikeBlockerDialog_Repeat::
	msgbox Ouderkerk_Text_FietsBlokkerRepeat, MSGBOX_DEFAULT
	return

Common_Movement_PushPlayerBackSouth:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

@ Shared "Healer" NPC (Scientist sprite) - reused on multiple maps. Just
@ point any map's Healer object_event's script straight at this symbol,
@ no per-map wrapper needed since it doesn't reference its own local_id.
Common_EventScript_Healer::
	lock
	faceplayer
	msgbox Common_Text_HealerHeals, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end

Ouderkerk_Text_FietsBlokkerFirst:
	.string "Hey Fritta, van Ouderkerk naar\n"
	.string "Amsterdam is echt tering ver.\p"
	.string "Dat moet je niet zonder fiets\n"
	.string "doen! Je hebt geen fiets?\p"
	.string "Check even de Ouderkerker Plas\n"
	.string "hier ten oosten, ik zag Jonas\l"
	.string "daar op een enge Fatbike rondfietsen$"

Ouderkerk_Text_FietsBlokkerRepeat:
	.string "Haal die Fatbike van Jonas bij\n"
	.string "de Plas, dan kan je naar 'dam$"

Ouderkerk_Text_FietsBlokkerSuccess:
	.string "Success met naar de stad\n"
	.string "fietsen gek, echt een\l"
	.string "pokke eind$"

Common_Text_HealerHeals:
	.string "Hier heb je 5-MEO-MIPT,\n"
	.string "daar gaan die beesies hard van$"
