Ouderker_CasHouse_1F_MapScripts::
	.byte 0

Ouderker_CasHouse_1F_EventScript_Karin::
	lock
	faceplayer
	msgbox Ouderker_CasHouse_1F_Text_Karin, MSGBOX_DEFAULT
	release
	end

Ouderker_CasHouse_1F_EventScript_Anton::
	lock
	faceplayer
	msgbox Ouderker_CasHouse_1F_Text_Anton, MSGBOX_DEFAULT
	goto_if_set FLAG_TALKED_TO_ANTON, Ouderker_CasHouse_1F_EventScript_AntonDone
	setflag FLAG_TALKED_TO_ANTON
	msgbox Ouderker_CasHouse_1F_Text_AntonGift, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_POTION, 5

Ouderker_CasHouse_1F_EventScript_AntonDone::
	release
	end

Ouderker_CasHouse_1F_Text_Karin:
	.string "Karin: ALS IK JE NOG EEN KEER\n"
	.string "ZIE GAMEN MOET JE NAAR HAVO$"

Ouderker_CasHouse_1F_Text_Anton:
	.string "Anton: Ik ga zo even eitje\n"
	.string "bakken voor ontbijt, eet je\l"
	.string "mee?$"

Ouderker_CasHouse_1F_Text_AntonGift:
	.string "Hier neem deze mee voor\n"
	.string "onderweg$"

Ouderker_CasHouse_1F_EventScript_Dog1::
	lock
	faceplayer
	msgbox Ouderker_CasHouse_1F_Text_Dog1, MSGBOX_DEFAULT
	release
	end

Ouderker_CasHouse_1F_EventScript_Dog2::
	lock
	faceplayer
	msgbox Ouderker_CasHouse_1F_Text_Dog2, MSGBOX_DEFAULT
	release
	end

Ouderker_CasHouse_1F_Text_Dog1:
	.string "BRAM: Blaf Blaf$"

Ouderker_CasHouse_1F_Text_Dog2:
	.string "R.I.P. Theun man sadge$"
