Ouderkerk_MargrietHouse_2F_MapScripts::
#if OUDERKERK_DEBUG_BLAZIKEN
	map_script MAP_SCRIPT_ON_LOAD, Ouderkerk_MargrietHouse_2F_OnLoad
#endif
	.byte 0

#if OUDERKERK_DEBUG_BLAZIKEN
@ [DEBUG/TEST TOOL] Build-time toggle (OUDERKERK_DEBUG_BLAZIKEN=1) - grants the
@ debug Lv.100 BLAZIKEN (SWIFT) once, the moment New Game drops the player in
@ this room, instead of via the starter-ball pick. Gated on FLAG_DEBUG_GOT_BLAZIKEN
@ so re-entering this room doesn't grant it again. See spec.md's "Debug options".
Ouderkerk_MargrietHouse_2F_OnLoad:
	goto_if_set FLAG_DEBUG_GOT_BLAZIKEN, Ouderkerk_MargrietHouse_2F_OnLoad_Done
	givemon SPECIES_BLAZIKEN, 100, move1=MOVE_SWIFT
	setflag FLAG_DEBUG_GOT_BLAZIKEN
Ouderkerk_MargrietHouse_2F_OnLoad_Done:
	end
#endif

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
