Ouderkerkerplas_MapScripts::
	.byte 0

Ouderkerkerplas_EventScript_RijkePensionado::
	trainerbattle_single TRAINER_RIJKE_PENSIONADO, Ouderkerkerplas_Text_RijkePensionadoIntro, Ouderkerkerplas_Text_RijkePensionadoDefeat
	msgbox Ouderkerkerplas_Text_RijkePensionadoDefeat, MSGBOX_AUTOCLOSE
	end

Ouderkerkerplas_EventScript_Sara::
	trainerbattle_single TRAINER_SARA, Ouderkerkerplas_Text_SaraIntro, Ouderkerkerplas_Text_SaraDefeat
	msgbox Ouderkerkerplas_Text_SaraDefeat, MSGBOX_AUTOCLOSE
	end

Ouderkerkerplas_EventScript_Jeffrey::
	lock
	faceplayer
	msgbox Ouderkerkerplas_Text_Jeffrey, MSGBOX_DEFAULT
	release
	end

@ Passing an event_script to trainerbattle_single (4th arg) makes it run that
@ script automatically, still locked, the instant Jonas is defeated for the
@ first time - same mechanism vanilla Gym Leaders use to keep the player
@ locked in conversation through their post-battle badge/TM hand-off (see
@ RustboroCity_Gym_EventScript_Roxanne for the reference pattern). Without
@ this param the player would unlock right after the defeat text and the
@ bike/TM hand-off would only fire on a second, separate re-talk.
Ouderkerkerplas_EventScript_Jonas::
	trainerbattle_single TRAINER_OUDERKERK_JONAS, Ouderkerkerplas_Text_JonasIntro, Ouderkerkerplas_Text_JonasDefeat, Ouderkerkerplas_EventScript_JonasPostBattle
	msgbox Ouderkerkerplas_Text_JonasDefeat, MSGBOX_AUTOCLOSE
	end

@ Only reached automatically on the first win (see comment above). Every
@ later re-talk, Jonas is already flagged defeated, so trainerbattle_single
@ skips straight to the AUTOCLOSE line in Ouderkerkerplas_EventScript_Jonas
@ instead of running this again.
Ouderkerkerplas_EventScript_JonasPostBattle::
	msgbox Ouderkerkerplas_Text_JonasGivesBike, MSGBOX_DEFAULT
	additem ITEM_MACH_BIKE
	additem ITEM_ACRO_BIKE
	setflag FLAG_GOT_FATBIKE
	giveitem ITEM_TM_DRAGON_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

Ouderkerkerplas_Text_RijkePensionadoIntro:
	.string "RIJKE PENSIONADO: Ik ben met\n"
	.string "pensioen, lekker vissen.$"

Ouderkerkerplas_Text_RijkePensionadoDefeat:
	.string "RIJKE PENSIONADO: Jij hebt sowieso\n"
	.string "geen Porsche! PAUPER!!$"

Ouderkerkerplas_Text_SaraIntro:
	.string "SARA: Hey FRITS, ik ben JONAS\n"
	.string "zusje.$"

Ouderkerkerplas_Text_SaraDefeat:
	.string "SARA: JONAS fietst wat verder op op\n"
	.string "zijn leipe fatbike. Hij pakt je!$"

Ouderkerkerplas_Text_Jeffrey:
	.string "JEFFREY: Ik kan alles\n"
	.string "BOUWWWHEEEH!!!$"

Ouderkerkerplas_Text_JonasIntro:
	.string "JONAS: Hey FRITS, lang niet\n"
	.string "gezien pik.\p"
	.string "Of je mijn fiets mag lenen?\n"
	.string "Absoluut niet, ik klap je\l"
	.string "liever op je bek ouwe.\p"
	.string "Kom dan!!$"

Ouderkerkerplas_Text_JonasDefeat:
	.string "JONAS: Ja kutzooi, daar gaat\n"
	.string "m'n dikke PhatFour$"

Ouderkerkerplas_Text_JonasGivesBike:
	.string "JONAS: Nou oke I guess dat je\n"
	.string "m'n opgevoerde monster mag\l"
	.string "hebben.\p"
	.string "Ik moet toch naar huis, er is\n"
	.string "betonrot in de vloer$"
