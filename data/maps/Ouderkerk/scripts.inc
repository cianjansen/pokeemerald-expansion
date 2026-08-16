Ouderkerk_MapScripts::
	.byte 0

Ouderkerk_EventScript_FietsBlokkerTalk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FATBIKE, Ouderkerk_EventScript_FietsBlokkerTalk_Done
	call Ouderkerk_EventScript_FietsBlokkerDialog
	release
	end

Ouderkerk_EventScript_FietsBlokkerTalk_Done::
	release
	end

Ouderkerk_EventScript_FietsBlokkerTrigger::
	lockall
	goto_if_set FLAG_GOT_FATBIKE, Ouderkerk_EventScript_FietsBlokkerTrigger_Done
	applymovement LOCALID_OUDERKERK_FIETS_BLOKKER, Common_Movement_FaceUp
	waitmovement 0
	call Ouderkerk_EventScript_FietsBlokkerDialog
	closemessage
	applymovement LOCALID_PLAYER, Ouderkerk_Movement_PushPlayerBackSouth
	waitmovement 0
	releaseall
	end

Ouderkerk_EventScript_FietsBlokkerTrigger_Done::
	releaseall
	end

@ Shared dialog: shows the first-time or repeat message depending on
@ FLAG_TALKED_TO_FIETS_BLOKKER. Caller is responsible for lock/faceplayer
@ and closing/releasing afterward. Must be entered via `call`.
Ouderkerk_EventScript_FietsBlokkerDialog::
	goto_if_set FLAG_TALKED_TO_FIETS_BLOKKER, Ouderkerk_EventScript_FietsBlokkerDialog_Repeat
	msgbox Ouderkerk_Text_FietsBlokkerFirst, MSGBOX_DEFAULT
	setflag FLAG_TALKED_TO_FIETS_BLOKKER
	return

Ouderkerk_EventScript_FietsBlokkerDialog_Repeat::
	msgbox Ouderkerk_Text_FietsBlokkerRepeat, MSGBOX_DEFAULT
	return

Ouderkerk_Movement_PushPlayerBackSouth:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

Ouderkerk_Text_FietsBlokkerFirst:
	.string "Hey Fritta, van Ouderkerk naar\n"
	.string "Amsterdam is echt tering ver.\p"
	.string "Dat moet je niet zonder fiets\n"
	.string "doen! Je hebt geen fiets?\p"
	.string "Check even de Ouderkerker Plas\n"
	.string "hier ten zuiden, ik zag Jonas\l"
	.string "daar op een enge Fatbike rondfietsen$"

Ouderkerk_Text_FietsBlokkerRepeat:
	.string "Haal die Fatbike van Jonas bij\n"
	.string "de Plas, dan kan je naar 'dam$"
