Limburg_Pokecenter_MapScripts::
	.byte 0

@ Same as AmsterdamZuidPokeCenter_EventScript_Healer, just its own respawn point.
Limburg_Pokecenter_EventScript_Healer::
	lock
	faceplayer
	msgbox Common_Text_HealerHeals, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_LIMBURG_POKECENTER
	special HealPlayerParty
	release
	end

Limburg_Pokecenter_EventScript_DrugsUser::
	lock
	faceplayer
	msgbox Limburg_Pokecenter_Text_DrugsUser, MSGBOX_DEFAULT
	release
	end

Limburg_Pokecenter_Text_DrugsUser:
	.string "Ik ben op zoek naar kanker\n"
	.string "dikke sammies$"
