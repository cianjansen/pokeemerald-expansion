GroningenFieneke_MapScripts::
	.byte 0

GroningenFieneke_EventScript_FienekeLoot::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FIENEKE_LOOT, GroningenFieneke_EventScript_FienekeLootRepeat
	msgbox GroningenFieneke_Text_FienekeLootFirst, MSGBOX_DEFAULT
	giveitem ITEM_LEFTOVERS, 6
	giveitem ITEM_FOCUS_SASH, 6
	setflag FLAG_GOT_FIENEKE_LOOT
	release
	end

GroningenFieneke_EventScript_FienekeLootRepeat::
	msgbox GroningenFieneke_Text_FienekeLootRepeat, MSGBOX_DEFAULT
	release
	end

GroningenFieneke_Text_FienekeLootFirst:
	.string "FRITS: Ey man zieke loot drop\n"
	.string "hier van dat oude lijk$"

GroningenFieneke_Text_FienekeLootRepeat:
	.string "FRITS: Shit man het stinkt hier$"
