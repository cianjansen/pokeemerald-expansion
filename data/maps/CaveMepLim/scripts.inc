CaveMepLim_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CaveMepLim_OnResume
	.byte 0

@ Same pattern as Route3Huizen_OnResume/_EventScript_TryRemoveKyogre -
@ FLAG_SYS_CTRL_OBJ_DELETE is set right before the special call in
@ CaveMepLim_EventScript_Groudon and only cleared after it returns.
@ Returning from the battle resumes the field (running this OnResume) before
@ that clearflag line executes, so this is what actually removes Groudon's
@ sprite from the currently-loaded map.
CaveMepLim_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CaveMepLim_EventScript_TryRemoveGroudon
	end

CaveMepLim_EventScript_TryRemoveGroudon::
	removeobject VAR_LAST_TALKED
	return

CaveMepLim_EventScript_Gerrie::
	lock
	faceplayer
	msgbox CaveMepLim_Text_Gerrie, MSGBOX_DEFAULT
	release
	end

CaveMepLim_Text_Gerrie:
	.string "GERRIE: Ik ga gewoon 50k\n"
	.string "lene van d'n Lumberjack$"

CaveMepLim_EventScript_Ries::
	lock
	faceplayer
	msgbox CaveMepLim_Text_Ries, MSGBOX_DEFAULT
	release
	end

CaveMepLim_Text_Ries:
	.string "RIES: Van een KALE KIP\n"
	.string "kente nie pluk$"

CaveMepLim_EventScript_Rikkert::
	lock
	faceplayer
	msgbox CaveMepLim_Text_Rikkert, MSGBOX_DEFAULT
	release
	end

CaveMepLim_Text_Rikkert:
	.string "RIKKERT: NEEUHHH ME\n"
	.string "MANTAAAAA$"

@ Wild Groudon encounter - talks, then battles once and disappears for good
@ regardless of outcome (win/lose/catch/flee), same pattern as
@ Route3Huizen_EventScript_Kyogre.
CaveMepLim_EventScript_Groudon::
	lock
	faceplayer
	msgbox CaveMepLim_Text_GroudonIntro, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_GROUDON, 50
	setflag FLAG_HIDE_CAVE_MEP_LIM_GROUDON
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end

CaveMepLim_Text_GroudonIntro:
	.string "Faka niffo$"
