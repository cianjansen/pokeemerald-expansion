MeppelPokeCenter_MapScripts::
	.byte 0

@ Same as AmsterdamZuidPokeCenter_EventScript_Healer, just its own respawn point.
MeppelPokeCenter_EventScript_Healer::
	lock
	faceplayer
	msgbox Common_Text_HealerHeals, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_MEPPEL_POKE_CENTER
	special HealPlayerParty
	release
	end

MeppelPokeCenter_EventScript_DrugsUser::
	lock
	faceplayer
	msgbox MeppelPokeCenter_Text_DrugsUser, MSGBOX_DEFAULT
	release
	end

MeppelPokeCenter_Text_DrugsUser:
	.string "Ik rook zware sjek, maar\n"
	.string "eigenlijk zoek ik naar crack$"
