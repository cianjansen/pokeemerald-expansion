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

AmsterdamZuid_EventScript_DrugslabSign::
	msgbox AmsterdamZuid_Text_DrugslabSign, MSGBOX_SIGN
	end

@ Same shared pattern as Common_EventScript_BikeBlocker* (Ouderkerk/scripts.inc):
@ talk path shows one message pre-purchase and a different one after,
@ trigger path (walking into the 4 coord_events in front of her) turns her
@ to face the player, blocks with the same line every time pre-purchase,
@ then pushes the player back a tile. Once FLAG_MATCHA_PURCHASED is set,
@ both paths just let the player through.
AmsterdamZuid_EventScript_MatchaBlockerTalk::
	lock
	faceplayer
	goto_if_set FLAG_MATCHA_PURCHASED, AmsterdamZuid_EventScript_MatchaBlockerTalk_Done
	msgbox AmsterdamZuid_Text_MatchaBlockerRepeat, MSGBOX_DEFAULT
	release
	end

AmsterdamZuid_EventScript_MatchaBlockerTalk_Done::
	msgbox AmsterdamZuid_Text_MatchaBlockerSuccess, MSGBOX_DEFAULT
	release
	end

AmsterdamZuid_EventScript_MatchaBlockerTrigger::
	lockall
	goto_if_set FLAG_MATCHA_PURCHASED, AmsterdamZuid_EventScript_MatchaBlockerTrigger_Done
	applymovement LOCALID_MATCHA_BLOCKER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AmsterdamZuid_Text_MatchaBlockerTrigger, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, AmsterdamZuid_Movement_PushPlayerBackSouth
	waitmovement 0
	releaseall
	end

AmsterdamZuid_EventScript_MatchaBlockerTrigger_Done::
	releaseall
	end

AmsterdamZuid_Movement_PushPlayerBackSouth:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

AmsterdamZuid_EventScript_MatchaEnjoyer1::
	lock
	faceplayer
	msgbox AmsterdamZuid_Text_MatchaEnjoyer1, MSGBOX_DEFAULT
	release
	end

AmsterdamZuid_EventScript_MatchaEnjoyer2::
	lock
	faceplayer
	msgbox AmsterdamZuid_Text_MatchaEnjoyer2, MSGBOX_DEFAULT
	release
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

AmsterdamZuid_Text_MatchaBlockerTrigger:
	.string "Je bent echt niet in Amsterdam\n"
	.string "Zuid geweest als je geen\l"
	.string "Matcha hebt geprobeerd.\p"
	.string "Beter koop je er eentje tegen\n"
	.string "een redelijke prijs in het\l"
	.string "cafe om de hoek$"

AmsterdamZuid_Text_MatchaBlockerRepeat:
	.string "Probeer eerst een lekkere\n"
	.string "Matcha, dan praten we verder$"

AmsterdamZuid_Text_MatchaBlockerSuccess:
	.string "Lekker toch zo'n zeewier soep$"

AmsterdamZuid_Text_MatchaEnjoyer1:
	.string "Hmm slurppppp lekker groen$"

AmsterdamZuid_Text_MatchaEnjoyer2:
	.string "Heerlijk zo'n Matcha, en\n"
	.string "helemaal niet duur$"

AmsterdamZuid_Text_DrugslabSign:
	.string "Drugslab\n"
	.string "Pillen te koop$"
