GroningenPokeCenter_MapScripts::
	.byte 0

@ Same as AmsterdamZuidPokeCenter_EventScript_Healer, just its own respawn point.
GroningenPokeCenter_EventScript_Healer::
	lock
	faceplayer
	msgbox Common_Text_HealerHeals, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_GRONINGEN_POKE_CENTER
	special HealPlayerParty
	release
	end

GroningenPokeCenter_EventScript_DrugsUser::
	lock
	faceplayer
	msgbox GroningenPokeCenter_Text_DrugsUser, MSGBOX_DEFAULT
	release
	end

GroningenPokeCenter_Text_DrugsUser:
	.string "Als ik niet direct een heel\n"
	.string "postzegelvel aan LSD vind ga ik\l"
	.string "tamam$"
