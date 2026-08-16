Ouderkerk_MargrietHouse_2F_MapScripts::
	.byte 0

Ouderkerk_MargrietHouse_2F_EventScript_Margriet::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_MARGRIET, Ouderkerk_MargrietHouse_2F_EventScript_MargrietRepeat
	msgbox Ouderkerk_MargrietHouse_2F_Text_MargrietFirst, MSGBOX_DEFAULT
	setflag FLAG_TALKED_TO_MARGRIET
	setrespawn HEAL_LOCATION_OUDERKERK_MARGRIET_HOUSE_2F
	special HealPlayerParty
	release
	end

Ouderkerk_MargrietHouse_2F_EventScript_MargrietRepeat::
	msgbox Ouderkerk_MargrietHouse_2F_Text_MargrietRepeat, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_OUDERKERK_MARGRIET_HOUSE_2F
	special HealPlayerParty
	release
	end

Ouderkerk_MargrietHouse_2F_Text_MargrietFirst:
	.string "MARGRIET: Oh, Frits, dat was lekker\p"
	.string "Hoe gaat het eigenlijk met mijn zoon\n"
	.string "CIAN? En de andere jongens?\p"
	.string "Je hebt ze lang niet gesproken, hè?\n"
	.string "Vanwege die kutsfeer in de call?\p"
	.string "Ga alsjeblieft voor me op zoek naar\n"
	.string "mijn zoon en breng me nieuws over\l"
	.string "hoe het met hem gaat.\p"
	.string "Als het je lukt doen we anaaltje!\p"
	.string "Neem vooral een goeie Ponkimon mee\n"
	.string "voor onderweg!$"

Ouderkerk_MargrietHouse_2F_Text_MargrietRepeat:
	.string "MARGRIET: Heb je mijn zoon CIAN al\n"
	.string "gevonden? Denk aan die anaaltje!$"
