Ouderkerk_MargrietHouse_2F_MapScripts::
#if OUDERKERK_DEBUG_RAYQUAZA
	map_script MAP_SCRIPT_ON_LOAD, Ouderkerk_MargrietHouse_2F_OnLoad
#endif
	.byte 0

#if OUDERKERK_DEBUG_RAYQUAZA
@ [DEBUG/TEST TOOL] Build-time toggle (OUDERKERK_DEBUG_RAYQUAZA=1) - grants the
@ debug Lv.100 RAYQUAZA once, the moment New Game drops the player in this
@ room, instead of via the starter-ball pick. Maxed IVs (31) and EVs (252,
@ this hack's Gen 6+ per-stat cap - see P_EV_CAP) in every stat, HARDY nature
@ so nothing's held back by a hindering nature, OUTRAGE as its first move,
@ and a held Persim Berry (cures confusion specifically, unlike Lum's
@ cure-anything). Gated on FLAG_DEBUG_GOT_RAYQUAZA so re-entering this room
@ doesn't grant it again. See spec.md's "Debug options".
Ouderkerk_MargrietHouse_2F_OnLoad:
	goto_if_set FLAG_DEBUG_GOT_RAYQUAZA, Ouderkerk_MargrietHouse_2F_OnLoad_Done
	givemon SPECIES_RAYQUAZA, 100, item=ITEM_PERSIM_BERRY, nature=NATURE_HARDY, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_OUTRAGE
	setflag FLAG_DEBUG_GOT_RAYQUAZA
	setflag FLAG_SYS_POKEMON_GET
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
