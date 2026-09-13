GroningenNam_1F_MapScripts::
	.byte 0

GroningenNam_1F_EventScript_Trainer1::
	trainerbattle_single TRAINER_GRONINGEN_NAM_1, GroningenNam_1F_Text_Trainer1Intro, GroningenNam_1F_Text_Trainer1Defeat
	msgbox GroningenNam_1F_Text_Trainer1Defeat, MSGBOX_AUTOCLOSE
	end

GroningenNam_1F_EventScript_Trainer2::
	trainerbattle_single TRAINER_GRONINGEN_NAM_2, GroningenNam_1F_Text_Trainer2Intro, GroningenNam_1F_Text_Trainer2Defeat
	msgbox GroningenNam_1F_Text_Trainer2Defeat, MSGBOX_AUTOCLOSE
	end

@ Shared by both NAM_BOSS and HABIB_NAM - whichever one the player talks to
@ runs this same script and fights TRAINER_NAM_BAAS. Uses lockall/releaseall
@ (not lock/faceplayer) since it moves a second object (HABIB_NAM) after the
@ battle regardless of which of the two was actually talked to, same pattern
@ as vanilla JaggedPass_EventScript_MagmaHideoutGuard.
GroningenNam_1F_EventScript_NamBoss::
	lockall
	goto_if_set FLAG_NAM_BEATEN, GroningenNam_1F_EventScript_NamBossRepeat
	msgbox GroningenNam_1F_Text_HibobPreBattle, MSGBOX_DEFAULT
	msgbox GroningenNam_1F_Text_NamBaasIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_NAM_BAAS, GroningenNam_1F_Text_NamBaasDefeat
	msgbox GroningenNam_1F_Text_HabierAfterNamBoss, MSGBOX_DEFAULT
	applymovement HABIB_NAM, GroningenNam_1F_Movement_HabibWalkOff
	waitmovement 0
	removeobject HABIB_NAM
	setflag FLAG_NAM_BEATEN
	clearflag FLAG_HIDE_GRONINGEN_HABIB_HUIS
	releaseall
	end

GroningenNam_1F_EventScript_NamBossRepeat::
	msgbox GroningenNam_1F_Text_NamBaasDefeat, MSGBOX_DEFAULT
	releaseall
	end

GroningenNam_1F_Movement_HabibWalkOff:
	walk_left
	walk_left
	walk_left
	step_end

GroningenNam_1F_Text_Trainer1Intro:
	.string "Exxon mobile pompte hier 10\n"
	.string "miljoen kuub per dag$"

GroningenNam_1F_Text_Trainer1Defeat:
	.string "Toen de gaskraan dicht moest,\n"
	.string "gingen de kraan van mijn\l"
	.string "tranen open$"

GroningenNam_1F_Text_Trainer2Intro:
	.string "Als we gewoon op Geert\n"
	.string "stemmen mag de kraan weer open$"

GroningenNam_1F_Text_Trainer2Defeat:
	.string "MINDER, MINDER, MINDER$"

GroningenNam_1F_Text_HibobPreBattle:
	.string "HIBOB: Mijn gasrekeningen\n"
	.string "zijn echt ZAAD. Beter openen\l"
	.string "jullie die kraan weer anders\l"
	.string "ga ik sws flamen$"

GroningenNam_1F_Text_NamBaasIntro:
	.string "NAM BAAS: Ey dikke lul man,\n"
	.string "fuck you got mine.\p"
	.string "Ik heb lekker geharkt met de\n"
	.string "grond leegtrekken, nu mag jij\l"
	.string "met de aardbevingen dealen$"

GroningenNam_1F_Text_NamBaasDefeat:
	.string "Chapeau...$"

GroningenNam_1F_Text_HabierAfterNamBoss:
	.string "HABIER: Ai gg ez idiot, ik\n"
	.string "pak de sleutels om de kraan\l"
	.string "open te knallen. Ik ga naar\l"
	.string "huis, MATTEO moet nog de fles$"
