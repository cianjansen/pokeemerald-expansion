AmsterdamZuidBaandersHouse_MapScripts::
	.byte 0

AmsterdamZuidBaandersHouse_EventScript_MarkBaanders::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_MARK_BAANDERS, AmsterdamZuidBaandersHouse_EventScript_MarkBaandersRepeat
	msgbox AmsterdamZuidBaandersHouse_Text_MarkBaandersTooth, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox AmsterdamZuidBaandersHouse_Text_MarkBaandersGoudsmid, MSGBOX_DEFAULT
	setflag FLAG_TALKED_TO_MARK_BAANDERS
	release
	end

AmsterdamZuidBaandersHouse_EventScript_MarkBaandersRepeat::
	msgbox AmsterdamZuidBaandersHouse_Text_MarkBaandersGoudsmid, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidBaandersHouse_EventScript_Moeder::
	lock
	faceplayer
	msgbox AmsterdamZuidBaandersHouse_Text_Moeder, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidBaandersHouse_EventScript_TrapBlocker::
	lock
	faceplayer
	msgbox AmsterdamZuidBaandersHouse_Text_TrapBlocker, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidBaandersHouse_Text_MarkBaandersTooth:
	.string "Kerel, ik heb mijn tand\n"
	.string "doormidden gesneden.\p"
	.string "Hier, je mag de rest\n"
	.string "hebben$"

AmsterdamZuidBaandersHouse_Text_MarkBaandersGoudsmid:
	.string "Ik ga sorry zeggen tegen\n"
	.string "Goudsmid$"

AmsterdamZuidBaandersHouse_Text_Moeder:
	.string "Als mijn Markie geschorst\n"
	.string "wordt, bel ik gewoon de\l"
	.string "rector$"

AmsterdamZuidBaandersHouse_Text_TrapBlocker:
	.string "Hier de trap op kan je alle\n"
	.string "koele legendaries vinden$"
