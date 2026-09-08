Route3Huizen_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route3Huizen_OnResume
	.byte 0

@ FLAG_SYS_CTRL_OBJ_DELETE is set right before the special call in
@ Route3Huizen_EventScript_Kyogre and only cleared after it returns.
@ Returning from the battle resumes the field (running this OnResume) before
@ that clearflag line executes, so this is what actually removes Kyogre's
@ sprite from the currently-loaded map - setting FLAG_HIDE_ROUTE3HUIZEN_KYOGRE
@ alone only stops it from respawning on a future map (re)load, it doesn't
@ retroactively hide an object already spawned this session. Same pattern as
@ CMRoute2VondelPark_OnResume/_EventScript_TryRemoveMew.
Route3Huizen_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route3Huizen_EventScript_TryRemoveKyogre
	end

Route3Huizen_EventScript_TryRemoveKyogre::
	removeobject VAR_LAST_TALKED
	return

Route3Huizen_EventScript_Henk::
	trainerbattle_single TRAINER_OUDERKERK_HENK, Route3Huizen_Text_HenkIntro, Route3Huizen_Text_HenkDefeat
	msgbox Route3Huizen_Text_HenkDefeat, MSGBOX_AUTOCLOSE
	end

Route3Huizen_EventScript_Gerard::
	trainerbattle_single TRAINER_OUDERKERK_GERARD, Route3Huizen_Text_GerardIntro, Route3Huizen_Text_GerardDefeat
	msgbox Route3Huizen_Text_GerardDefeat, MSGBOX_AUTOCLOSE
	end

Route3Huizen_EventScript_Tim::
	trainerbattle_single TRAINER_OUDERKERK_TIM, Route3Huizen_Text_TimIntro, Route3Huizen_Text_TimDefeat
	msgbox Route3Huizen_Text_TimDefeat, MSGBOX_AUTOCLOSE
	end

Route3Huizen_EventScript_Bram::
	trainerbattle_single TRAINER_OUDERKERK_BRAM, Route3Huizen_Text_BramIntro, Route3Huizen_Text_BramDefeat
	msgbox Route3Huizen_Text_BramDefeat, MSGBOX_AUTOCLOSE
	end

Route3Huizen_EventScript_Kevin::
	trainerbattle_single TRAINER_OUDERKERK_KEVIN, Route3Huizen_Text_KevinIntro, Route3Huizen_Text_KevinDefeat
	msgbox Route3Huizen_Text_KevinDefeat, MSGBOX_AUTOCLOSE
	end

Route3Huizen_EventScript_Sanne::
	trainerbattle_single TRAINER_OUDERKERK_SANNE, Route3Huizen_Text_SanneIntro, Route3Huizen_Text_SanneDefeat
	msgbox Route3Huizen_Text_SanneDefeat, MSGBOX_AUTOCLOSE
	end

Route3Huizen_EventScript_Max::
	trainerbattle_single TRAINER_OUDERKERK_MAX, Route3Huizen_Text_MaxIntro, Route3Huizen_Text_MaxDefeat
	msgbox Route3Huizen_Text_MaxDefeat, MSGBOX_AUTOCLOSE
	end

Route3Huizen_Text_HenkIntro:
	.string "FREEK VONK: Ik ga sws een dikke\n"
	.string "aligator vangen$"

Route3Huizen_Text_HenkDefeat:
	.string "FREEK VONK: Niet eens een\n"
	.string "goudvis te vinden hier man$"

Route3Huizen_Text_GerardIntro:
	.string "GERARD: We krijgen ons geld niet\n"
	.string "terug, en ze hebben OOK geen\l"
	.string "andere kamer$"

Route3Huizen_Text_GerardDefeat:
	.string "GERARD: Ik sloop die hele\n"
	.string "kanker kamer$"

Route3Huizen_Text_TimIntro:
	.string "JOCH: Pas op, het is glad in\n"
	.string "brabant$"

Route3Huizen_Text_TimDefeat:
	.string "JOCH: BEL DE WOUTEN, BEL DE\n"
	.string "WOUTEN$"

Route3Huizen_Text_BramIntro:
	.string "LAU: Tiny, met jou\n"
	.string "kerstversiering ophangen krijg\l"
	.string "ik altijd de godkankertering van$"

Route3Huizen_Text_BramDefeat:
	.string "LAU: KERRMISSSS$"

Route3Huizen_Text_KevinIntro:
	.string "KEVIN: Ik had 6 maanden geleden\n"
	.string "al gezegd dat ik deze zaterdag\l"
	.string "een feestje zou geven$"

Route3Huizen_Text_KevinDefeat:
	.string "KEVIN: EN WAT DENK JE?? OPEN\n"
	.string "KANKER ZIJKANT$"

Route3Huizen_Text_SanneIntro:
	.string "FAMKE LOUISE: Ik ben altijd\n"
	.string "op me monnie$"

Route3Huizen_Text_SanneDefeat:
	.string "FAMKE LOUISE: Ik doe NIET meer\n"
	.string "mee hashtag vriendenPeople$"

Route3Huizen_Text_MaxIntro:
	.string "MAX: Hé, jij hier! Kom, even een\n"
	.string "rustig potje samen.$"

Route3Huizen_Text_MaxDefeat:
	.string "MAX: Lekker gespeeld, zoals altijd.\n"
	.string "Zullen we straks een stukje\l"
	.string "hardlopen?$"

@ Wild Kyogre encounter - talks, then battles once and disappears for good
@ regardless of outcome (win/lose/catch/flee), same pattern as
@ FLAG_HIDE_VONDELPARK_MEW: the hide flag is set on the object itself
@ (map.json "flag") and gets set right before the battle starts, not after,
@ so it takes effect no matter how the battle ends. Uses
@ special BattleSetup_StartLegendaryBattle (not plain dowildbattle) to match
@ how the real MarineCave_End Kyogre static encounter is implemented.
Route3Huizen_EventScript_Kyogre::
	lock
	faceplayer
	msgbox Route3Huizen_Text_KyogreIntro, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KYOGRE, 50
	setflag FLAG_HIDE_ROUTE3HUIZEN_KYOGRE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end

Route3Huizen_Text_KyogreIntro:
	.string "Ey ja fuck it man hier is wat\n"
	.string "water dus waarom niet deze\l"
	.string "bolle vis$"

Route3Huizen_EventScript_HuizenSign::
	msgbox Route3Huizen_Text_HuizenSign, MSGBOX_SIGN
	end

Route3Huizen_Text_HuizenSign:
	.string "Huizen\n"
	.string "(2)$"

@ Overhead flavor trigger - fires every time the player steps on this
@ tile, no gating flag, and pushes them back one step west. Same
@ push-back idiom as Route3GenHuis_EventScript_ImipodoTrigger.
Route3Huizen_EventScript_NiemandInHuizenTrigger::
	lockall
	msgbox Route3Huizen_Text_NiemandInHuizen, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route3Huizen_Movement_PlayerPushWest
	waitmovement 0
	releaseall
	end

Route3Huizen_Movement_PlayerPushWest:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

Route3Huizen_Text_NiemandInHuizen:
	.string "FRITS: Noh man er woont sws\n"
	.string "verder niemand in Huizen$"
