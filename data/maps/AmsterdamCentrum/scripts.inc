AmsterdamCentrum_MapScripts::
	.byte 0

@ Shared entry point for FRITS_MOM's own "talk" script AND all 3 approach
@ triggers south of her (17,21-23) - same behavior either way: greet, walk
@ into the house together, set FLAG_FRITS_MOM_MET (which also hides her via
@ her own object_event "flag" field). goto_if_set below is what makes the
@ triggers "inactive" afterward, since the object itself being hidden
@ already takes care of the direct-talk path on its own.
@ Doesn't let the player's forced walk actually land on the real warp tile
@ (17,19) - it only walks them as far as (17,20), then the map change is
@ done explicitly with warp+waitstate. Letting a scripted applymovement walk
@ the player onto a live warp tile races the engine's own arrival-triggered
@ transition against the still-pending waitmovement and hangs the script -
@ same pattern PetalburgCity_EventScript_WalkToWallyHouse uses to lead the
@ player into Wally's house. FRITS_MOM does walk fully onto the door tile,
@ same as PetalburgCity_Movement_WalkInsideHouseWallysDad - that's fine,
@ NPCs walking over a warp tile don't trigger it, only the player does.
AmsterdamCentrum_EventScript_FritsMom::
	goto_if_set FLAG_FRITS_MOM_MET, AmsterdamCentrum_EventScript_FritsMomInactive
	lockall
	msgbox AmsterdamCentrum_Text_FritsMomGreeting, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_FRITS_MOM_MET
	applymovement FRITS_MOM, AmsterdamCentrum_Movement_MomWalkIntoHouse
	applymovement LOCALID_PLAYER, AmsterdamCentrum_Movement_PlayerWalkIntoHouse
	waitmovement 0
	hideobjectat LOCALID_PLAYER, MAP_AMSTERDAM_CENTRUM
	warp MAP_AMSTERDAM_CENTRUM_FRITS_HUIS, 3, 7
	waitstate
	releaseall
	end

AmsterdamCentrum_EventScript_FritsMomInactive::
	end

AmsterdamCentrum_Movement_MomWalkIntoHouse:
	walk_up
	set_invisible
	step_end

AmsterdamCentrum_Movement_PlayerWalkIntoHouse:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

AmsterdamCentrum_Text_FritsMomGreeting:
	.string "FRITS' MA: Heyy Friedel! Ik ben\n"
	.string "je moeder, en ik ben NIET dood!\p"
	.string "Wat fijn dat je terug in\n"
	.string "Amsterdam bent, kom even naar\l"
	.string "binnen dan maak ik een kopje\l"
	.string "thee voor je.$"

AmsterdamCentrum_EventScript_AmsterdamCentrumSign::
	msgbox AmsterdamCentrum_Text_AmsterdamCentrumSign, MSGBOX_SIGN
	end

AmsterdamCentrum_EventScript_FritsFamHuisSign::
	msgbox AmsterdamCentrum_Text_FritsFamHuisSign, MSGBOX_SIGN
	end

AmsterdamCentrum_EventScript_MelkwegSign::
	msgbox AmsterdamCentrum_Text_MelkwegSign, MSGBOX_SIGN
	end

AmsterdamCentrum_EventScript_DrugslabSign::
	msgbox AmsterdamCentrum_Text_DrugslabSign, MSGBOX_SIGN
	end

AmsterdamCentrum_EventScript_Rechtboomsloot47DSign::
	msgbox AmsterdamCentrum_Text_Rechtboomsloot47DSign, MSGBOX_SIGN
	end

AmsterdamCentrum_Text_AmsterdamCentrumSign:
	.string "Amsterdam Centrum\n"
	.string "Kanker veel toeristen hier man$"

AmsterdamCentrum_Text_FritsFamHuisSign:
	.string "Frits' fam huis\n"
	.string "Frits, Frits' ma (niet dood)$"

AmsterdamCentrum_Text_MelkwegSign:
	.string "De Melkweg\n"
	.string "Vanavond Fiesta Macumba\l"
	.string "Beter hou je van Latina billen$"

AmsterdamCentrum_Text_DrugslabSign:
	.string "Drugslab\n"
	.string "Poeder te koop$"

AmsterdamCentrum_Text_Rechtboomsloot47DSign:
	.string "Rechtboomsloot 47D\n"
	.string "Nihao$"
