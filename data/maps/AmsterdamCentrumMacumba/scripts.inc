AmsterdamCentrumMacumba_MapScripts::
	.byte 0

AmsterdamCentrumMacumba_EventScript_Bouncer::
	lock
	faceplayer
	msgbox AmsterdamCentrumMacumba_Text_Bouncer, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumMacumba_Text_Bouncer:
	.string "Beter heb je geen condies bij\n"
	.string "je. Daar doen ze niet aan in\l"
	.string "Colombia$"

AmsterdamCentrumMacumba_EventScript_LockerGuy::
	lock
	faceplayer
	msgbox AmsterdamCentrumMacumba_Text_LockerGuy, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumMacumba_Text_LockerGuy:
	.string "Ja godverdomme man, was het\n"
	.string "nou kluisje 492 of 924$"

AmsterdamCentrumMacumba_EventScript_LatinaEnjoyer2::
	lock
	faceplayer
	msgbox AmsterdamCentrumMacumba_Text_LatinaEnjoyer2, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumMacumba_Text_LatinaEnjoyer2:
	.string "Pienso en tu pretty face...\n"
	.string "Y ese CULO ENORME$"

AmsterdamCentrumMacumba_EventScript_Latina::
	lock
	faceplayer
	msgbox AmsterdamCentrumMacumba_Text_Latina, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumMacumba_Text_Latina:
	.string "Hola papi, quieres perrear\n"
	.string "conmigo? Jij hebt vast losse\l"
	.string "heupjes$"

AmsterdamCentrumMacumba_EventScript_StageBouncer::
	lock
	faceplayer
	msgbox AmsterdamCentrumMacumba_Text_StageBouncer, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumMacumba_Text_StageBouncer:
	.string "Het beste deel van mijn job is\n"
	.string "het uitzicht. Overal dikke\l"
	.string "Latina billen$"

AmsterdamCentrumMacumba_EventScript_Niek::
	lock
	faceplayer
	msgbox AmsterdamCentrumMacumba_Text_Niek, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumMacumba_Text_Niek:
	.string "NIEK: Ze spelen helemaal niks\n"
	.string "van de nummers die ik ken.\p"
	.string "Even snel kijken hoeveel het\n"
	.string "staat bij de Graafschap in de\l"
	.string "kkd$"

AmsterdamCentrumMacumba_EventScript_Ivonne::
	lock
	faceplayer
	msgbox AmsterdamCentrumMacumba_Text_Ivonne, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumMacumba_Text_Ivonne:
	.string "IVONNE: Cian? He was here\n"
	.string "before, but he just left to go\l"
	.string "home with a cute girl.\p"
	.string "A real cougar! A proper\n"
	.string "mamacita...$"

@ MR_MACUMBA's speech, then FRITS gets walked out onto the dance floor and
@ spins before the player is warped home. Movement assumes the player talks
@ to MR_MACUMBA (5,4) from directly below at (5,5): walk_up onto his row,
@ walk_left to column 2 (reaching tile 2,4), then walk_down to tile 2,9,
@ matching the two waypoints given. Lands 1 tile north of the FritsHuis
@ front-door warp coords AmsterdamCentrum_EventScript_FritsMom already
@ warps to (3,7), i.e. (3,6), so FRITS arrives already a step inside.
AmsterdamCentrumMacumba_EventScript_MrMacumba::
	lock
	faceplayer
	msgbox AmsterdamCentrumMacumba_Text_MrMacumba, MSGBOX_DEFAULT
	msgbox AmsterdamCentrumMacumba_Text_FritsDanceFloor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, AmsterdamCentrumMacumba_Movement_FritsWalkToDanceFloor
	waitmovement 0
	applymovement LOCALID_PLAYER, AmsterdamCentrumMacumba_Movement_FritsSpin
	waitmovement 0
	setflag FLAG_VISITED_MACUMBA
	hideobjectat LOCALID_PLAYER, MAP_AMSTERDAM_CENTRUM_MACUMBA
	warp MAP_AMSTERDAM_CENTRUM_FRITS_HUIS, 3, 6
	waitstate
	release
	end

AmsterdamCentrumMacumba_Movement_FritsWalkToDanceFloor:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Fifteen full turns in place (up/right/down/left x15) - FRITS spins about
@ 15 times.
AmsterdamCentrumMacumba_Movement_FritsSpin:
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	walk_in_place_faster_up
	walk_in_place_faster_right
	walk_in_place_faster_down
	walk_in_place_faster_left
	step_end

AmsterdamCentrumMacumba_Text_MrMacumba:
	.string "Familia familia, Amsterdam\n"
	.string "Amsterdam! If she does not\l"
	.string "want to be touched, you do\p"
	.string "not touch her$"

AmsterdamCentrumMacumba_Text_FritsDanceFloor:
	.string "FRITS: Yooo deze beats gaan\n"
	.string "stiekem kanker hard. Ummpa\l"
	.string "ummpa. Ik ga even dik hier$"

@ Dance floor exit blocker - same push-back idiom as
@ Route3GenHuis_EventScript_ImipodoTrigger/_Movement_PlayerPushSouth, no
@ gating flag so it fires every time the player tries to leave this way.
AmsterdamCentrumMacumba_EventScript_ExitBlockerTrigger::
	lockall
	msgbox AmsterdamCentrumMacumba_Text_NotGoingHomeYet, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, AmsterdamCentrumMacumba_Movement_PlayerPushNorth
	waitmovement 0
	releaseall
	end

AmsterdamCentrumMacumba_Movement_PlayerPushNorth:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

AmsterdamCentrumMacumba_Text_NotGoingHomeYet:
	.string "FRITS: Noh man ik ga nog niet\n"
	.string "naar huis. daar is het\l"
	.string "sowieso een kutsfeer$"
