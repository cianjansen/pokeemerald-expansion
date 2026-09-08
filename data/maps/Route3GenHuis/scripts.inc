Route3GenHuis_MapScripts::
	.byte 0

Route3GenHuis_EventScript_GenMa::
	lock
	faceplayer
	msgbox Route3GenHuis_Text_GenMa, MSGBOX_DEFAULT
	release
	end

Route3GenHuis_Text_GenMa:
	.string "Ik schaam me voor mijn zoon,\n"
	.string "daarom kom ik nooit mijn huis\l"
	.string "uit.\p"
	.string "Wat als de buren me zouden\n"
	.string "zien??$"

@ Post-battle reward only reached automatically on the first win (see
@ CLAUDE.md's trainerbattle_single rule) - still locked from the battle,
@ same pattern as Ouderkerkerplas_EventScript_JonasPostBattle.
Route3GenHuis_EventScript_Gen::
	trainerbattle_single TRAINER_OUDERKERK_GEN, Route3GenHuis_Text_GenIntro, Route3GenHuis_Text_GenDefeat, Route3GenHuis_EventScript_GenPostBattle
	msgbox Route3GenHuis_Text_GenDefeat, MSGBOX_AUTOCLOSE
	end

Route3GenHuis_EventScript_GenPostBattle::
	msgbox Route3GenHuis_Text_GenPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

Route3GenHuis_Text_GenIntro:
	.string "GEN: Nou maar he maar kijk\n"
	.string "luister man, ik zeg je hoe het\l"
	.string "zit met vrouwen.\p"
	.string "Ze zijn allemaal hetzelfde en\n"
	.string "ze protecten elkaar altijd en\l"
	.string "als een man er iets van zegt\p"
	.string "wordt ie canceled man...$"

Route3GenHuis_Text_GenDefeat:
	.string "GEN: Alleen maar omdat ik een\n"
	.string "man ben heh$"

Route3GenHuis_Text_GenPostBattle:
	.string "GEN: Ai fuck it dan maar naar\n"
	.string "Bangkok om te sauzen$"

@ Overhead insult trigger - fires every time the player steps on this
@ tile, no gating flag, and pushes them back one step south. Same
@ push-back idiom as CMRoute2VondelPark_EventScript_TrinetteBlockerTrigger.
Route3GenHuis_EventScript_ImipodoTrigger::
	lockall
	msgbox Route3GenHuis_Text_Imipodo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route3GenHuis_Movement_PlayerPushSouth
	waitmovement 0
	releaseall
	end

Route3GenHuis_Movement_PlayerPushSouth:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

Route3GenHuis_Text_Imipodo:
	.string "IMIPODO: HOE KAN JE ZO SLECHT\n"
	.string "ZIJN??$"
