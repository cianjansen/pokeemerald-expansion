Limburg_MapScripts::
	.byte 0

Limburg_EventScript_Girl::
	lock
	faceplayer
	msgbox Limburg_Text_Girl, MSGBOX_DEFAULT
	release
	end

Limburg_Text_Girl:
	.string "Vlaai high! Snap je? Nou kijk,\n"
	.string "vlaai komt uit Limburg en het\p"
	.string "is een woordgrap want vlaai en\n"
	.string "fly klinken hetzelfde.\p"
	.string "Grappg hé?$"
