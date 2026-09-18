AmsterdamCentrumFritsHuis_2F_MapScripts::
	.byte 0

AmsterdamCentrumFritsHuis_2F_EventScript_FritsMom::
	lock
	faceplayer
	msgbox AmsterdamCentrumFritsHuis_2F_Text_FritsMom, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumFritsHuis_2F_Text_FritsMom:
	.string "FRITS' MA: Ohhh Frits, ik wist\n"
	.string "niet dat je vanavond thuis zou\l"
	.string "slapen.\p"
	.string "Mama was met deze knappe\n"
	.string "jongen van een feestje naar\l"
	.string "huis gegaan.\p"
	.string "Zoals Jesse Habets zei: Ik\n"
	.string "schaam me$"

@ The reveal fight. Post-battle runs the same Hall of Fame + credits
@ sequence as EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame's
@ ending (dofieldeffect FLDEFF_HALL_OF_FAME_RECORD then special GameClear),
@ minus the vanilla-specific Wallace walk-in and game-clear flag setting -
@ those are all vanilla-story checkpoints that don't exist in this hack.
AmsterdamCentrumFritsHuis_2F_EventScript_Cian::
	trainerbattle_single TRAINER_CIAN, AmsterdamCentrumFritsHuis_2F_Text_CianIntro, AmsterdamCentrumFritsHuis_2F_Text_CianDefeat, AmsterdamCentrumFritsHuis_2F_EventScript_CianPostBattle
	msgbox AmsterdamCentrumFritsHuis_2F_Text_CianDefeat, MSGBOX_AUTOCLOSE
	end

AmsterdamCentrumFritsHuis_2F_EventScript_CianPostBattle::
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setrespawn HEAL_LOCATION_AMSTERDAM_CENTRUM_FRITS_HUIS
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	releaseall
	end

AmsterdamCentrumFritsHuis_2F_Text_CianIntro:
	.string "CIAN: Hallo Fredde. Margriet\n"
	.string "heeft je gevraagd me te\l"
	.string "zoeken?\p"
	.string "Je bent toch niet serieus dat\n"
	.string "je met mijn ma naar bed bent\l"
	.string "gegaan?!\p"
	.string "Daarvoor maak ik je kapot$"

AmsterdamCentrumFritsHuis_2F_Text_CianDefeat:
	.string "CIAN: Jij wint, maar ik heb\n"
	.string "nog steeds je ma gepaald.\p"
	.string "Binnenkort krijg je een klein\n"
	.string "broertje, en dan ben ik\l"
	.string "officieel je papa.$"
