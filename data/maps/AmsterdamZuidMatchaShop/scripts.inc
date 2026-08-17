AmsterdamZuidMatchaShop_MapScripts::
	.byte 0

@ FLAG_TOBIAS_BEATEN is used as a stand-in for "can afford this" - Tobias's
@ reward is a flat 999,999, so beating him always covers the 500,000 price.
@ Deliberately not a real checkmoney/balance check (per user request), just
@ this flag gate, so a player can never get soft-locked by an edge case
@ where they have the flag but somehow spent the money on something else.
AmsterdamZuidMatchaShop_EventScript_Seller::
	lock
	faceplayer
	goto_if_set FLAG_MATCHA_PURCHASED, AmsterdamZuidMatchaShop_EventScript_SellerRepeat
	msgbox AmsterdamZuidMatchaShop_Text_SellerOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, AmsterdamZuidMatchaShop_EventScript_SellerDeclined
	goto_if_unset FLAG_TOBIAS_BEATEN, AmsterdamZuidMatchaShop_EventScript_SellerNoMoney
	removemoney 500000, 0
	setflag FLAG_MATCHA_PURCHASED
	msgbox AmsterdamZuidMatchaShop_Text_FritsGatverdamme, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidMatchaShop_EventScript_SellerDeclined::
	release
	end

AmsterdamZuidMatchaShop_EventScript_SellerNoMoney::
	msgbox AmsterdamZuidMatchaShop_Text_SellerNoMoney, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidMatchaShop_EventScript_SellerRepeat::
	msgbox AmsterdamZuidMatchaShop_Text_SellerRepeat, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidMatchaShop_EventScript_Enjoyer1::
	lock
	faceplayer
	msgbox AmsterdamZuidMatchaShop_Text_Enjoyer1, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidMatchaShop_EventScript_Enjoyer2::
	lock
	faceplayer
	msgbox AmsterdamZuidMatchaShop_Text_Enjoyer2, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidMatchaShop_Text_SellerOffer:
	.string "Wil je een zalige groene\n"
	.string "Ceremonial Slurp Saus\l"
	.string "Matcha kopen?\p"
	.string "Kost maar 500.000$"

AmsterdamZuidMatchaShop_Text_SellerNoMoney:
	.string "Huh ben je pauper ofzo?\n"
	.string "Je pinpas blokkeert...\p"
	.string "Beter naar het Casino gaan\n"
	.string "om wat bij te cashen$"

AmsterdamZuidMatchaShop_Text_FritsGatverdamme:
	.string "FRITS: Gatverdamme deze shit\n"
	.string "smaakt naar gras$"

AmsterdamZuidMatchaShop_Text_SellerRepeat:
	.string "Goor heh$"

AmsterdamZuidMatchaShop_Text_Enjoyer1:
	.string "Ik heb me nier verkocht voor\n"
	.string "een groene gelukskegel$"

AmsterdamZuidMatchaShop_Text_Enjoyer2:
	.string "Ik vind het stiekem\n"
	.string "helemaal niet lekker,\p"
	.string "maar alle hippe mensen\n"
	.string "drinken dit$"
