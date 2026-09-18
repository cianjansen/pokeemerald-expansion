Route5Meppel_MapScripts::
	.byte 0

Route5Meppel_EventScript_Jace::
	lock
	faceplayer
	msgbox Route5Meppel_Text_Jace, MSGBOX_DEFAULT
	release
	end

Route5Meppel_Text_Jace:
	.string "Mijn papa Melvin zit achter\n"
	.string "alle Svetlana's in het dorp\l"
	.string "aan$"

Route5Meppel_EventScript_WelcomeSign::
	msgbox Route5Meppel_Text_WelcomeSign, MSGBOX_SIGN
	end

Route5Meppel_Text_WelcomeSign:
	.string "Welkom in Meppel. Probably de\n"
	.string "oudste stad van Nederland als\l"
	.string "je het aan de familie Dop\p"
	.string "vraagt$"

Route5Meppel_EventScript_FridaSign::
	msgbox Route5Meppel_Text_FridaSign, MSGBOX_SIGN
	end

Route5Meppel_Text_FridaSign:
	.string "Frida's krot. Goeie odds dat\n"
	.string "Milan hier ook is want die is\l"
	.string "ook Meppelaar$"

Route5Meppel_EventScript_LimburgSign::
	msgbox Route5Meppel_Text_LimburgSign, MSGBOX_SIGN
	end

Route5Meppel_Text_LimburgSign:
	.string "Ja vriend je gaat naar\n"
	.string "Limburg moeten of je het nou\l"
	.string "wil of niet$"

Route5Meppel_EventScript_Maxie::
	trainerbattle_single TRAINER_MAXIE_MEPPEL, Route5Meppel_Text_MaxieIntro, Route5Meppel_Text_MaxieDefeat
	msgbox Route5Meppel_Text_MaxieDefeat, MSGBOX_AUTOCLOSE
	end

Route5Meppel_Text_MaxieIntro:
	.string "MAXIE: Ik ga je kont vingeren$"

Route5Meppel_Text_MaxieDefeat:
	.string "Kanker Alien$"
