CMroute1_MapScripts::
	.byte 0

CMroute1_EventScript_AmstelSign::
	msgbox CMroute1_Text_AmstelSign, MSGBOX_SIGN
	end

CMroute1_EventScript_HeyHoeKomJijHierSign::
	msgbox CMroute1_Text_HeyHoeKomJijHierSign, MSGBOX_SIGN
	end

CMroute1_EventScript_VeiligBinnenDeRingSign::
	msgbox CMroute1_Text_VeiligBinnenDeRingSign, MSGBOX_SIGN
	end

CMroute1_EventScript_Joris::
	trainerbattle_single TRAINER_OUDERKERK_JORIS, CMroute1_Text_JorisIntro, CMroute1_Text_JorisDefeat
	msgbox CMroute1_Text_JorisDefeat, MSGBOX_AUTOCLOSE
	end

CMroute1_EventScript_Bartel::
	trainerbattle_single TRAINER_OUDERKERK_BARTEL, CMroute1_Text_BartelIntro, CMroute1_Text_BartelDefeat
	msgbox CMroute1_Text_BartelDefeat, MSGBOX_AUTOCLOSE
	end

CMroute1_EventScript_Gerda::
	trainerbattle_single TRAINER_OUDERKERK_GERDA, CMroute1_Text_GerdaIntro, CMroute1_Text_GerdaDefeat
	msgbox CMroute1_Text_GerdaDefeat, MSGBOX_AUTOCLOSE
	end

CMroute1_EventScript_Japie::
	trainerbattle_single TRAINER_OUDERKERK_JAPIE, CMroute1_Text_JapieIntro, CMroute1_Text_JapieDefeat
	msgbox CMroute1_Text_JapieDefeat, MSGBOX_AUTOCLOSE
	end

CMroute1_EventScript_Jelle::
	trainerbattle_single TRAINER_OUDERKERK_JELLE, CMroute1_Text_JelleIntro, CMroute1_Text_JelleDefeat
	msgbox CMroute1_Text_JelleDefeat, MSGBOX_AUTOCLOSE
	end

CMroute1_EventScript_Truus::
	trainerbattle_single TRAINER_OUDERKERK_TRUUS, CMroute1_Text_TruusIntro, CMroute1_Text_TruusDefeat
	msgbox CMroute1_Text_TruusDefeat, MSGBOX_AUTOCLOSE
	end

CMroute1_EventScript_Piet::
	trainerbattle_single TRAINER_OUDERKERK_PIET, CMroute1_Text_PietIntro, CMroute1_Text_PietDefeat
	msgbox CMroute1_Text_PietDefeat, MSGBOX_AUTOCLOSE
	end

CMroute1_Text_JorisIntro:
	.string "JORIS: Mijn passie was werken\n"
	.string "in de tabaksindustrie$"

CMroute1_Text_JorisDefeat:
	.string "JORIS: Ugh ugh kuch kuch rochel\n"
	.string "rochel uhhhuhhh...$"

CMroute1_Text_BartelIntro:
	.string "BARTEL: Ik ga je vissen$"

CMroute1_Text_BartelDefeat:
	.string "BARTEL: Je hebt me gefist...$"

CMroute1_Text_GerdaIntro:
	.string "GERDA: Ik heb zo'n schijthekel\n"
	.string "aan al die racefiets mannetjes$"

CMroute1_Text_GerdaDefeat:
	.string "GERDA: Ik ga een stok in je wiel\n"
	.string "steken$"

CMroute1_Text_JapieIntro:
	.string "JAPIE: ZOOM ZOOM$"

CMroute1_Text_JapieDefeat:
	.string "JAPIE: Mijn fiets weegt duidelijk\n"
	.string "12 gram te veel.\p"
	.string "Tijd om te investeren in\n"
	.string "Karbon Fieber.$"

CMroute1_Text_JelleIntro:
	.string "JELLE: Ik ga voor de\n"
	.string "bolletjestrui$"

CMroute1_Text_JelleDefeat:
	.string "JELLE: Fuck it ik ga doping doen$"

CMroute1_Text_TruusIntro:
	.string "TRUUS: Ik heb dubbel pensioen$"

CMroute1_Text_TruusDefeat:
	.string "TRUUS: VERHOOG DE AOW$"

CMroute1_Text_PietIntro:
	.string "PIET: Ik word sowieso niet\n"
	.string "gepakt bij de zelfscan$"

CMroute1_Text_PietDefeat:
	.string "PIET: Noh man ik zweer, moet op\n"
	.string "ander bonnetje$"

CMroute1_Text_AmstelSign:
	.string "De Amstel. Amsterdam: 40km$"

CMroute1_Text_HeyHoeKomJijHierSign:
	.string "Hey hoe kom jij hier pik$"

CMroute1_Text_VeiligBinnenDeRingSign:
	.string "Pfff bijna weer veilig binnen\l"
	.string "de ring$"
