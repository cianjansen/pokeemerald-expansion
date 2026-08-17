AmsterdamZuidPokeCenter_MapScripts::
	.byte 0

@ Same as Common_EventScript_Healer (Ouderkerk/scripts.inc) but also sets
@ this room as the player's respawn point, same as Margriet's healer script.
AmsterdamZuidPokeCenter_EventScript_Healer::
	lock
	faceplayer
	msgbox Common_Text_HealerHeals, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_AMSTERDAM_ZUID_POKE_CENTER
	special HealPlayerParty
	release
	end

AmsterdamZuidPokeCenter_EventScript_PillUser::
	lock
	faceplayer
	msgbox AmsterdamZuidPokeCenter_Text_PillUser, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidPokeCenter_Text_PillUser:
	.string "Ik heb meer 3MMC nodig nuuu$"
