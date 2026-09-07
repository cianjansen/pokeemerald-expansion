AmsterdamCentrumPokeCenter_MapScripts::
	.byte 0

@ Same as AmsterdamZuidPokeCenter_EventScript_Healer, just its own respawn point.
AmsterdamCentrumPokeCenter_EventScript_Healer::
	lock
	faceplayer
	msgbox Common_Text_HealerHeals, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_AMSTERDAM_CENTRUM_POKE_CENTER
	special HealPlayerParty
	release
	end

AmsterdamCentrumPokeCenter_EventScript_PillUser::
	lock
	faceplayer
	msgbox AmsterdamCentrumPokeCenter_Text_PillUser, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumPokeCenter_Text_PillUser:
	.string "Ik heb al m'n pokemon kaarten\nverkocht om meer 4-o-med te\lkunnen kopen$"
