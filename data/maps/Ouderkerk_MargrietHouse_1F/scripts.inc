Ouderkerk_MargrietHouse_1F_MapScripts::
	.byte 0

Ouderkerk_MargrietHouse_1F_EventScript_ShinxBall::
	lock
	faceplayer
	msgbox Ouderkerk_MargrietHouse_1F_Text_MoetJeZonShinx, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Ouderkerk_MargrietHouse_1F_EventScript_PickAnother
	givemon SPECIES_SHINX, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Ouderkerk_MargrietHouse_1F_EventScript_GaveStarter
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Ouderkerk_MargrietHouse_1F_EventScript_GaveStarter
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Ouderkerk_MargrietHouse_1F_EventScript_RioluBall::
	lock
	faceplayer
	msgbox Ouderkerk_MargrietHouse_1F_Text_MoetJeZonRiolu, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Ouderkerk_MargrietHouse_1F_EventScript_PickAnother
	givemon SPECIES_RIOLU, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Ouderkerk_MargrietHouse_1F_EventScript_GaveStarter
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Ouderkerk_MargrietHouse_1F_EventScript_GaveStarter
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Ouderkerk_MargrietHouse_1F_EventScript_PiplupBall::
	lock
	faceplayer
	msgbox Ouderkerk_MargrietHouse_1F_Text_MoetJeZonPiplup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Ouderkerk_MargrietHouse_1F_EventScript_PickAnother
	givemon SPECIES_PIPLUP, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Ouderkerk_MargrietHouse_1F_EventScript_GaveStarter
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Ouderkerk_MargrietHouse_1F_EventScript_GaveStarter
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Ouderkerk_MargrietHouse_1F_EventScript_PickAnother::
	msgbox Ouderkerk_MargrietHouse_1F_Text_OkeAndereDan, MSGBOX_DEFAULT
	release
	end

Ouderkerk_MargrietHouse_1F_EventScript_GaveStarter::
	setflag FLAG_GOT_MARGRIET_STARTER
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setflag FLAG_HIDE_MARGRIET_HOUSE_1F_STARTER_BALLS
	removeobject LOCALID_OUDERKERK_MARGRIET_HOUSE_1F_SHINX_BALL
	removeobject LOCALID_OUDERKERK_MARGRIET_HOUSE_1F_RIOLU_BALL
	removeobject LOCALID_OUDERKERK_MARGRIET_HOUSE_1F_PIPLUP_BALL
	additem ITEM_POKE_BALL, 50
	additem ITEM_GREAT_BALL, 50
	additem ITEM_ULTRA_BALL, 50
	msgbox Ouderkerk_MargrietHouse_1F_Text_EyNouSuccess, MSGBOX_DEFAULT
	release
	end

Ouderkerk_MargrietHouse_1F_Text_MoetJeZonShinx:
	.string "Moet je zo'n SHINX hebbe?\n"
	.string "Je mag maar een van de drie$"

Ouderkerk_MargrietHouse_1F_Text_MoetJeZonRiolu:
	.string "Moet je zo'n RIOLU hebbe?\n"
	.string "Je mag maar een van de drie$"

Ouderkerk_MargrietHouse_1F_Text_MoetJeZonPiplup:
	.string "Moet je zo'n PIPLUP hebbe?\n"
	.string "Je mag maar een van de drie$"

Ouderkerk_MargrietHouse_1F_Text_OkeAndereDan:
	.string "Oke nou pak een andere dan$"

Ouderkerk_MargrietHouse_1F_Text_EyNouSuccess:
	.string "Ey nou success ermee gek, wat\n"
	.string "een rotding$"

