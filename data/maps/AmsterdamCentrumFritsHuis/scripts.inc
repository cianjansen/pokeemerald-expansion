AmsterdamCentrumFritsHuis_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AmsterdamCentrumFritsHuis_OnFrame
	.byte 0

@ MAP_SCRIPT_ON_TRANSITION fires too early - while the map is still loading
@ mid-warp, before the fade-in/control handoff finishes - and a lockall
@ cutscene run from there deadlocks against the outer AmsterdamCentrum
@ script's own warp+waitstate (that's what was causing the black screen
@ hang). ON_FRAME_TABLE + map_script_2 VAR_TEMP_0, 0 is the actual vanilla
@ pattern for "run a locking cutscene right as you arrive" - see any
@ BattleFrontier_Battle*Room's own EnterRoom script for other examples.
@ VAR_TEMP_0 resets to 0 on every map load, so this fires on the first
@ frame the map is actually active and re-checks harmlessly every frame
@ after (goto_if_set below just no-ops once FLAG_FRITS_MOM_HOUSE_INTRO_DONE
@ is set).
AmsterdamCentrumFritsHuis_OnFrame:
	map_script_2 VAR_TEMP_0, 0, AmsterdamCentrumFritsHuis_EventScript_TeaScene
	.2byte 0

@ Path from the entry warp (3,7) to the seat 3 tiles right of FRITS_MOM's
@ (6,5) spot, i.e. (9,5): furniture blocks a straight walk along row y=5, so
@ this detours one row south (y=6) for the rightward stretch and only turns
@ back up onto the seat row for the final step - up 1, right 6, up 1.
AmsterdamCentrumFritsHuis_EventScript_TeaScene::
	goto_if_set FLAG_FRITS_MOM_HOUSE_INTRO_DONE, AmsterdamCentrumFritsHuis_EventScript_TeaSceneDone
	lockall
	applymovement FRITS_MOM, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, AmsterdamCentrumFritsHuis_Movement_PlayerWalkToSeat
	waitmovement 0
	msgbox AmsterdamCentrumFritsHuis_Text_MomTeaTalk, MSGBOX_DEFAULT
	setflag FLAG_FRITS_MOM_HOUSE_INTRO_DONE
	releaseall
	end

AmsterdamCentrumFritsHuis_EventScript_TeaSceneDone::
	end

AmsterdamCentrumFritsHuis_Movement_PlayerWalkToSeat:
	lock_facing_direction
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	unlock_facing_direction
	face_left
	step_end

AmsterdamCentrumFritsHuis_EventScript_FritsMomTalk::
	lock
	faceplayer
	goto_if_unset FLAG_FRITS_MOM_HOUSE_INTRO_DONE, AmsterdamCentrumFritsHuis_EventScript_TeaScene
	msgbox AmsterdamCentrumFritsHuis_Text_MomRepeat, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumFritsHuis_EventScript_BedroomBlocker::
	lockall
	msgbox AmsterdamCentrumFritsHuis_Text_BedroomBlocker, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, AmsterdamCentrumFritsHuis_Movement_PushPlayerBackSouth
	waitmovement 0
	releaseall
	end

AmsterdamCentrumFritsHuis_Movement_PushPlayerBackSouth:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

AmsterdamCentrumFritsHuis_Text_MomTeaTalk:
	.string "FRITS' MA: Wat brengt je\n"
	.string "eigenlijk naar Amsterdam? Oh je\l"
	.string "zoekt je ouwe vriend Cian?\p"
	.string "Geen idee waar die zou kunnen\n"
	.string "zijn, ik ken hem niet zo goed.\l"
	.string "Hoop dat het je lukt om hem te\l"
	.string "vinden schatje...$"

AmsterdamCentrumFritsHuis_Text_MomRepeat:
	.string "Succes met Cian vinden schat,\n"
	.string "zet hem op$"

AmsterdamCentrumFritsHuis_Text_BedroomBlocker:
	.string "FRITS' MA: Hey FREDJE, wat heb\n"
	.string "jij te zoeken in mijn\l"
	.string "slaapkamer? Ga daar maar niet\l"
	.string "naar binnen$"
