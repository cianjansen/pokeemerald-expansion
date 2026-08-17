AmsterdamZuid_MapScripts::
	.byte 0

AmsterdamZuid_EventScript_MilanTrajan::
	lock
	faceplayer
	msgbox AmsterdamZuid_Text_MilanTrajan, MSGBOX_DEFAULT
	release
	end

AmsterdamZuid_EventScript_AmsterdamZuidSign::
	msgbox AmsterdamZuid_Text_AmsterdamZuidSign, MSGBOX_SIGN
	end

AmsterdamZuid_EventScript_CasinoSign::
	msgbox AmsterdamZuid_Text_CasinoSign, MSGBOX_SIGN
	end

AmsterdamZuid_EventScript_VondelparkSign::
	msgbox AmsterdamZuid_Text_VondelparkSign, MSGBOX_SIGN
	end

AmsterdamZuid_EventScript_KoffieSign::
	msgbox AmsterdamZuid_Text_KoffieSign, MSGBOX_SIGN
	end

AmsterdamZuid_Text_MilanTrajan:
	.string "MILAN: Ik ben data acquisition\n"
	.string "manage... Kut nu ben ik de tel\l"
	.string "kwijt$"

AmsterdamZuid_Text_AmsterdamZuidSign:
	.string "Amsterdam Zuid\n"
	.string "Beter heb je oud geld$"

AmsterdamZuid_Text_CasinoSign:
	.string "Holland Casino Max Euweplein\n"
	.string "Fuck it alles op rood$"

AmsterdamZuid_Text_VondelparkSign:
	.string "Vondelpark\n"
	.string "Als je op een Fatbike komt\l"
	.string "krijg je de kogel$"

AmsterdamZuid_Text_KoffieSign:
	.string "Koffie en Matcha tegen een\n"
	.string "normale prijs$"
