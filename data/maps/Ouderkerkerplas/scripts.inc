Ouderkerkerplas_MapScripts::
	.byte 0

Ouderkerkerplas_EventScript_RijkePensionado::
	trainerbattle_single TRAINER_RIJKE_PENSIONADO, Ouderkerkerplas_Text_RijkePensionadoIntro, Ouderkerkerplas_Text_RijkePensionadoDefeat
	msgbox Ouderkerkerplas_Text_RijkePensionadoDefeat, MSGBOX_AUTOCLOSE
	end

Ouderkerkerplas_EventScript_Sara::
	trainerbattle_single TRAINER_SARA, Ouderkerkerplas_Text_SaraIntro, Ouderkerkerplas_Text_SaraDefeat
	msgbox Ouderkerkerplas_Text_SaraDefeat, MSGBOX_AUTOCLOSE
	end

Ouderkerkerplas_EventScript_Jeffrey::
	lock
	faceplayer
	msgbox Ouderkerkerplas_Text_Jeffrey, MSGBOX_DEFAULT
	release
	end

Ouderkerkerplas_Text_RijkePensionadoIntro:
	.string "RIJKE PENSIONADO: Ik ben met\n"
	.string "pensioen, lekker vissen.$"

Ouderkerkerplas_Text_RijkePensionadoDefeat:
	.string "RIJKE PENSIONADO: Jij hebt sowieso\n"
	.string "geen Porsche! PAUPER!!$"

Ouderkerkerplas_Text_SaraIntro:
	.string "SARA: Hey FRITS, ik ben JONAS\n"
	.string "zusje.$"

Ouderkerkerplas_Text_SaraDefeat:
	.string "SARA: JONAS fietst wat verder op op\n"
	.string "zijn leipe fatbike. Hij pakt je!$"

Ouderkerkerplas_Text_Jeffrey:
	.string "JEFFREY: Ik kan alles\n"
	.string "BOUWWWHEEEH!!!$"
