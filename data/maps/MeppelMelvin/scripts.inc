MeppelMelvin_MapScripts::
	.byte 0

MeppelMelvin_EventScript_Melvin::
	lock
	faceplayer
	msgbox MeppelMelvin_Text_Melvin, MSGBOX_DEFAULT
	release
	end

MeppelMelvin_Text_Melvin:
	.string "MELVIN: Ik ben nu met Olena,\n"
	.string "maar in het weekend ga ik\l"
	.string "vanuit mijn dikke benz\p"
	.string "toeteren naar alle\n"
	.string "minderjarige mokkeltjes$"

MeppelMelvin_EventScript_Svetlana::
	lock
	faceplayer
	msgbox MeppelMelvin_Text_Svetlana, MSGBOX_DEFAULT
	release
	end

MeppelMelvin_Text_Svetlana:
	.string "SVETLANA: Ik heet eigenlijk\n"
	.string "Vladislava, maar dat vergeet\l"
	.string "Melvin steeds. SLAVA UKRAINA$"
