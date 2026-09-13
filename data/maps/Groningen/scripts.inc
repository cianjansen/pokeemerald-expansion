Groningen_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Groningen_OnTransition
	.byte 0

@ Once HABIB is beaten, NAM_CAVE_BLOCKER steps one tile west (33,27 -> 32,27)
@ to let the player into the gas mine, same pattern as vanilla
@ PetalburgCity_EventScript_MoveGymBoyToWestEntrance.
Groningen_OnTransition:
	call_if_set FLAG_HABIB_BEATEN, Groningen_EventScript_MoveNamMedewerker
	end

Groningen_EventScript_MoveNamMedewerker::
	setobjectxyperm NAM_CAVE_BLOCKER, 32, 27
	return

Groningen_EventScript_Henk::
	lock
	faceplayer
	msgbox Groningen_Text_Henk, MSGBOX_DEFAULT
	release
	end

Groningen_EventScript_HonkyTonkEnjoyer::
	lock
	faceplayer
	msgbox Groningen_Text_HonkyTonkEnjoyer, MSGBOX_DEFAULT
	release
	end

Groningen_EventScript_NamMedewerker::
	lock
	faceplayer
	goto_if_set FLAG_HABIB_BEATEN, Groningen_EventScript_NamMedewerkerAfterHabib
	msgbox Groningen_Text_NamMedewerkerBeforeHabib, MSGBOX_DEFAULT
	release
	end

Groningen_EventScript_NamMedewerkerAfterHabib::
	msgbox Groningen_Text_NamMedewerkerAfterHabib, MSGBOX_DEFAULT
	release
	end

@ Fires from either of Groningen's two ground-shake trigger tiles (coord_events
@ at 14,22 and 22,34). Only live once HABIB_BEATEN, and only plays once ever
@ (FLAG_SEEN_GRONINGEN_AARDBEVING) - gate is checked ourselves since coord_event
@ triggers just fire on var_value == 0, not on any story flag.
Groningen_EventScript_AardbevingTrigger::
	lockall
	goto_if_unset FLAG_HABIB_BEATEN, Groningen_EventScript_AardbevingTrigger_Done
	goto_if_set FLAG_SEEN_GRONINGEN_AARDBEVING, Groningen_EventScript_AardbevingTrigger_Done
	setflag FLAG_SEEN_GRONINGEN_AARDBEVING
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 32 @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	msgbox Groningen_Text_Brrroom, MSGBOX_DEFAULT
	msgbox Groningen_Text_FritsAardbeving, MSGBOX_DEFAULT
	releaseall
	end

Groningen_EventScript_AardbevingTrigger_Done::
	releaseall
	end

Groningen_EventScript_GroningenSign::
	msgbox Groningen_Text_GroningenSign, MSGBOX_SIGN
	end

Groningen_EventScript_GasSign::
	msgbox Groningen_Text_GasSign, MSGBOX_SIGN
	end

Groningen_EventScript_NamSign::
	msgbox Groningen_Text_NamSign, MSGBOX_SIGN
	end

Groningen_EventScript_MegamansionSign::
	msgbox Groningen_Text_MegamansionSign, MSGBOX_SIGN
	end

Groningen_Text_GroningenSign:
	.string "Groningen\n"
	.string "8.9 op de schaal van Rigter$"

Groningen_Text_GasSign:
	.string "Gas mijn schacht (kk diep)$"

Groningen_Text_NamSign:
	.string "Nederlands Aardolie Maatschappij\n"
	.string "We trekken die hele teringzooi leeg$"

Groningen_Text_MegamansionSign:
	.string "Megamansion Habier$"

Groningen_Text_Henk:
	.string "HENK: Ik werk bij de NAM om\n"
	.string "mijn gezonde vrouw te kunnen\l"
	.string "verwennen$"

Groningen_Text_HonkyTonkEnjoyer:
	.string "Net zo'n lekkere berenhap\n"
	.string "gehaald bij GrillRoom HonkyTonk$"

Groningen_Text_NamMedewerkerBeforeHabib:
	.string "NAM Medewerker: Sorry, niemand\n"
	.string "krijgt toegang tot de gas\l"
	.string "mijn. De gaskraan is gesloten$"

Groningen_Text_NamMedewerkerAfterHabib:
	.string "NAM Medewerker: ai letsgoo we\n"
	.string "kunnen het weer leeg slurpen$"

Groningen_Text_Brrroom:
	.string "BRRRROOOOMMMMM$"

Groningen_Text_FritsAardbeving:
	.string "FRITS: Shit man wtf de hele\n"
	.string "grond is aan het trillen, ik\l"
	.string "moet zo snel mogelijk\l"
	.string "ondergrond schuilen$"
