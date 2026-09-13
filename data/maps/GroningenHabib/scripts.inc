GroningenHabib_MapScripts::
	.byte 0

@ HABIB_HUIS's map.json "flag" is FLAG_HIDE_GRONINGEN_HABIB_HUIS, which starts
@ set at New Game (EventScript_ResetAllMapFlags, data/scripts/new_game.inc) and
@ is cleared in GroningenNam_1F_EventScript_NamBossPostBattle once FLAG_NAM_BEATEN
@ is set. This is the correct mechanism for "hidden until an event elsewhere" -
@ a map_script (ON_TRANSITION/ON_LOAD/ON_RESUME) all run before object events
@ are spawned on a plain warp (LoadMapInStepsLocal case 2 vs InitObjectEventsLocal
@ case 3 in src/overworld.c), so a removeobject there is always a silent no-op;
@ the object-spawn code itself only ever checks the map.json flag field.
GroningenHabib_EventScript_HabibHuis::
	trainerbattle_single TRAINER_HABIB, GroningenHabib_Text_HabibIntro, GroningenHabib_Text_HabibDefeat, GroningenHabib_EventScript_HabibPostBattle
	msgbox GroningenHabib_Text_HabibDefeat, MSGBOX_AUTOCLOSE
	end

GroningenHabib_EventScript_HabibPostBattle::
	msgbox GroningenHabib_Text_HabibPostBattleTalk, MSGBOX_DEFAULT
	giveitem ITEM_TM_EARTHQUAKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_HABIB_BEATEN
	release
	end

GroningenHabib_EventScript_Leonie::
	lock
	faceplayer
	goto_if_set FLAG_HABIB_BEATEN, GroningenHabib_EventScript_LeonieAfterHabib
	msgbox GroningenHabib_Text_LeonieBeforeHabib, MSGBOX_DEFAULT
	release
	end

GroningenHabib_EventScript_LeonieAfterHabib::
	msgbox GroningenHabib_Text_LeonieAfterHabib, MSGBOX_DEFAULT
	release
	end

GroningenHabib_EventScript_Matteo::
	lock
	faceplayer
	msgbox GroningenHabib_Text_Matteo, MSGBOX_DEFAULT
	release
	end

GroningenHabib_Text_LeonieBeforeHabib:
	.string "LEONIE: Hey hey, welkom in\n"
	.string "Grijpskerk! Habib? Die is naar\l"
	.string "de NAM om ze te overtuigen de\l"
	.string "gaskraan weer te openen.\p"
	.string "Zo'n groot huis is vet duur\n"
	.string "stoken$"

GroningenHabib_Text_LeonieAfterHabib:
	.string "LEONIE: Yo het is gelukt, nu\n"
	.string "mag je wel warm douchen hoor$"

GroningenHabib_Text_Matteo:
	.string "MATTEO: WEEEEEEEEEH$"

GroningenHabib_Text_HabibIntro:
	.string "HABIBA: Jaja, ik ga die\n"
	.string "gaskraan wel openen zo gauw\l"
	.string "de verbouwing af is$"

GroningenHabib_Text_HabibDefeat:
	.string "KANKER ZAAD$"

GroningenHabib_Text_HabibPostBattleTalk:
	.string "HABIB: Oke fuck it here we\n"
	.string "go, ik open de gaskraan$"
