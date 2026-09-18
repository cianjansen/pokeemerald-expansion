CaveGROMEP_MapScripts::
	.byte 0

CaveGROMEP_EventScript_Anouk::
	trainerbattle_single TRAINER_CAVE_GROMEP_ANOUK, CaveGROMEP_Text_AnoukIntro, CaveGROMEP_Text_AnoukDefeat
	msgbox CaveGROMEP_Text_AnoukDefeat, MSGBOX_AUTOCLOSE
	end

CaveGROMEP_EventScript_Wouter::
	trainerbattle_single TRAINER_CAVE_GROMEP_WOUTER, CaveGROMEP_Text_WouterIntro, CaveGROMEP_Text_WouterDefeat
	msgbox CaveGROMEP_Text_WouterDefeat, MSGBOX_AUTOCLOSE
	end

CaveGROMEP_EventScript_Floris::
	trainerbattle_single TRAINER_CAVE_GROMEP_FLORIS, CaveGROMEP_Text_FlorisIntro, CaveGROMEP_Text_FlorisDefeat
	msgbox CaveGROMEP_Text_FlorisDefeat, MSGBOX_AUTOCLOSE
	end

CaveGROMEP_Text_AnoukIntro:
	.string "ANOUK: Voel je die kou al\n"
	.string "aankomen?$"

CaveGROMEP_Text_AnoukDefeat:
	.string "ANOUK: IJskoud... precies zoals\n"
	.string "mijn hart nu$"

CaveGROMEP_Text_WouterIntro:
	.string "WOUTER: Deze berg neem ik niet\n"
	.string "voor niks$"

CaveGROMEP_Text_WouterDefeat:
	.string "WOUTER: Kapot... net als mijn\n"
	.string "knieën$"

CaveGROMEP_Text_FlorisIntro:
	.string "FLORIS: Geld is geen probleem,\n"
	.string "verliezen anders wel$"

CaveGROMEP_Text_FlorisDefeat:
	.string "FLORIS: Dit kan mijn vader wel\n"
	.string "betalen zeg maar$"
