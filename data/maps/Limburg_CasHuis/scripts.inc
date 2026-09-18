Limburg_CasHuis_MapScripts::
	.byte 0

Limburg_CasHuis_EventScript_Cas::
	trainerbattle_single TRAINER_LIMBURG_CAS_HUIS_CAS, Limburg_CasHuis_Text_CasIntro, Limburg_CasHuis_Text_CasDefeat, Limburg_CasHuis_EventScript_CasLift
	goto Limburg_CasHuis_EventScript_CasLift

Limburg_CasHuis_EventScript_CasLift::
	msgbox Limburg_CasHuis_Text_CasLift, MSGBOX_DEFAULT
	warp MAP_AMSTERDAM_CENTRUM_MACUMBA, 0
	waitstate
	end

Limburg_CasHuis_EventScript_Clare::
	lock
	faceplayer
	msgbox Limburg_CasHuis_Text_Clare, MSGBOX_DEFAULT
	release
	end

Limburg_CasHuis_Text_CasIntro:
	.string "CAS: Ik heb net Baus' AP Yunara\n"
	.string "build gezien. Ziet er echt goed\l"
	.string "uit.$"

Limburg_CasHuis_Text_CasDefeat:
	.string "CAS: Vanavond laat ik de boys m'n\n"
	.string "nieuwe on hit Nami build zien.\p"
	.string "Ze gaan niet geloven wat ze\n"
	.string "zien!$"

Limburg_CasHuis_Text_CasLift:
	.string "Zoek je Cian? Die is met die\n"
	.string "latinas in fiesta Macumba.\l"
	.string "Ik geef je wel een liftje.$"

Limburg_CasHuis_Text_Clare:
	.string "CLARE: Alle meisjes zijn bang\n"
	.string "dat ze niet THICC genoeg zijn.$"
