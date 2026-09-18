MeppelFrida1_MapScripts::
	.byte 0

MeppelFrida1_EventScript_Frida::
	lock
	faceplayer
	msgbox MeppelFrida1_Text_Frida, MSGBOX_DEFAULT
	release
	end

MeppelFrida1_Text_Frida:
	.string "Huch huch kuch kuch.... FRITS:\n"
	.string "Shit man sws nog een zieke\l"
	.string "loot drop on the way$"

@ Same locked-through-post-battle pattern as Route3GenHuis_EventScript_Gen /
@ Ouderkerkerplas_EventScript_Jonas - the 4th arg runs automatically, still
@ locked, the instant Milan is defeated for the first time.
MeppelFrida1_EventScript_Milan::
	trainerbattle_single TRAINER_MILAN_MEPPEL, MeppelFrida1_Text_MilanIntro, MeppelFrida1_Text_MilanDefeat, MeppelFrida1_EventScript_MilanPostBattle
	msgbox MeppelFrida1_Text_MilanDefeat, MSGBOX_AUTOCLOSE
	end

MeppelFrida1_EventScript_MilanPostBattle::
	msgbox MeppelFrida1_Text_MilanCian, MSGBOX_DEFAULT
	release
	end

MeppelFrida1_Text_MilanIntro:
	.string "MILAN: Noh man ik ben echt\n"
	.string "geen Meppelaar hoor... Ik was\l"
	.string "gewoon op visite$"

MeppelFrida1_Text_MilanDefeat:
	.string "MILAN: Ik moet echt een baan\n"
	.string "vinden$"

MeppelFrida1_Text_MilanCian:
	.string "MILAN: Cian? Idk hij is toch\n"
	.string "vrienden met Cas? Anyway de\l"
	.string "game is linear dus je hebt\p"
	.string "geen keus anders dan naar\n"
	.string "Limburg gaan$"
