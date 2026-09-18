Limburg_WildersHouse_MapScripts::
	.byte 0

Limburg_WildersHouse_EventScript_Wilders::
	lock
	faceplayer
	msgbox Limburg_WildersHouse_Text_Wilders, MSGBOX_DEFAULT
	release
	end

Limburg_WildersHouse_Text_Wilders:
	.string "WILDERS: Wil je meer of minder\n"
	.string "dark types?$"
