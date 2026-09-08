Route3Huizen_MapScripts::
	.byte 0

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

Route3Huizen_EventScript_Sem::
	trainerbattle_single TRAINER_OUDERKERK_SEM, Route3Huizen_Text_SemIntro, Route3Huizen_Text_SemDefeat
	msgbox Route3Huizen_Text_SemDefeat, MSGBOX_AUTOCLOSE
	end

Route3Huizen_EventScript_Max::
	trainerbattle_single TRAINER_OUDERKERK_MAX, Route3Huizen_Text_MaxIntro, Route3Huizen_Text_MaxDefeat
	msgbox Route3Huizen_Text_MaxDefeat, MSGBOX_AUTOCLOSE
	end

Route3Huizen_Text_HenkIntro:
	.string "HENK: De hele dag nog geen beet.\n"
	.string "Misschien vang ik jou wel!$"

Route3Huizen_Text_HenkDefeat:
	.string "HENK: Weer met lege handen naar\n"
	.string "huis...$"

Route3Huizen_Text_GerardIntro:
	.string "GERARD: Even een potje voordat ik\n"
	.string "de kinderen ophaal.$"

Route3Huizen_Text_GerardDefeat:
	.string "GERARD: Oké, nu moet ik echt gaan.\n"
	.string "Ze staan te wachten.$"

Route3Huizen_Text_TimIntro:
	.string "TIM: Kijk! Deze heb ik allemaal\n"
	.string "zelf in het bos gevangen!$"

Route3Huizen_Text_TimDefeat:
	.string "TIM: Wow! Jij bent echt goed.$"

Route3Huizen_Text_BramIntro:
	.string "BRAM: Deze route loop ik elke\n"
	.string "ochtend voor mijn ontbijt.$"

Route3Huizen_Text_BramDefeat:
	.string "BRAM: Sterke benen, sterk team.\n"
	.string "Netjes gedaan.$"

Route3Huizen_Text_KevinIntro:
	.string "KEVIN: Yo. Lekker plekkie hier\n"
	.string "aan het strand, toch?$"

Route3Huizen_Text_KevinDefeat:
	.string "KEVIN: Rustig aan, man. Rustig aan.$"

Route3Huizen_Text_SanneIntro:
	.string "SANNE: Wat een prachtige dag om\n"
	.string "te trainen aan zee.$"

Route3Huizen_Text_SanneDefeat:
	.string "SANNE: Knap gespeeld. Chapeau.$"

Route3Huizen_Text_SemIntro:
	.string "SEM: Ik heb de zeldzame kevers.\n"
	.string "Niet die kleuterbeestjes.$"

Route3Huizen_Text_SemDefeat:
	.string "SEM: Hmpf. Volgende keer pak ik je.$"

Route3Huizen_Text_MaxIntro:
	.string "MAX: Hé, jij hier! Kom, even een\n"
	.string "rustig potje samen.$"

Route3Huizen_Text_MaxDefeat:
	.string "MAX: Lekker gespeeld, zoals altijd.\n"
	.string "Zullen we straks een stukje\l"
	.string "hardlopen?$"
