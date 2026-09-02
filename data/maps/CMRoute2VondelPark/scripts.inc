CMRoute2VondelPark_MapScripts::
	.byte 0

@ Trinette stands just north of the vertical blocker gate (x=57, y=20-22) and
@ is already facing down, so she's naturally facing the player as they
@ approach from the south - no applymovement facePlayer needed here, unlike
@ AndereFritsBlockerTrigger below.
CMRoute2VondelPark_EventScript_TrinetteBlockerTrigger::
	lockall
	goto_if_set FLAG_VONDELPARK_BLOCKER, CMRoute2VondelPark_EventScript_TrinetteBlockerTrigger_Done
	msgbox CMRoute2VondelPark_Text_TrinetteTriggerShout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, CMRoute2VondelPark_Movement_PushPlayerBackWest
	waitmovement 0
	releaseall
	end

CMRoute2VondelPark_EventScript_TrinetteBlockerTrigger_Done::
	releaseall
	end

CMRoute2VondelPark_Movement_PushPlayerBackWest:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

CMRoute2VondelPark_EventScript_Trinette::
	lock
	faceplayer
	goto_if_set FLAG_VONDELPARK_BLOCKER, CMRoute2VondelPark_EventScript_TrinetteRepeat
	msgbox CMRoute2VondelPark_Text_TrinetteTriggerShout, MSGBOX_DEFAULT
	release
	end

CMRoute2VondelPark_EventScript_TrinetteRepeat::
	msgbox CMRoute2VondelPark_Text_TrinetteRepeat, MSGBOX_DEFAULT
	release
	end

CMRoute2VondelPark_EventScript_AndereFritsBlockerTrigger::
	lockall
	goto_if_set FLAG_VONDELPARK_BLOCKER, CMRoute2VondelPark_EventScript_AndereFritsBlockerTrigger_Done
	applymovement VONDELPARK_ANDERE_FRITS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CMRoute2VondelPark_Text_AndereFritsTriggerShout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, CMRoute2VondelPark_Movement_PushPlayerBackSouth
	waitmovement 0
	releaseall
	end

CMRoute2VondelPark_EventScript_AndereFritsBlockerTrigger_Done::
	releaseall
	end

CMRoute2VondelPark_Movement_PushPlayerBackSouth:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

CMRoute2VondelPark_EventScript_AndereFrits::
	lock
	faceplayer
	goto_if_set FLAG_VONDELPARK_BLOCKER, CMRoute2VondelPark_EventScript_AndereFritsRepeat
	msgbox CMRoute2VondelPark_Text_AndereFritsIntro, MSGBOX_DEFAULT
	release
	end

CMRoute2VondelPark_EventScript_AndereFritsRepeat::
	msgbox CMRoute2VondelPark_Text_AndereFritsRepeat, MSGBOX_DEFAULT
	release
	end

CMRoute2VondelPark_EventScript_Djoko::
	trainerbattle_single TRAINER_OUDERKERK_DJOKO, CMRoute2VondelPark_Text_DjokoIntro, CMRoute2VondelPark_Text_DjokoDefeat
	msgbox CMRoute2VondelPark_Text_DjokoDefeat, MSGBOX_AUTOCLOSE
	end

CMRoute2VondelPark_EventScript_Nadal::
	trainerbattle_single TRAINER_OUDERKERK_NADAL, CMRoute2VondelPark_Text_NadalIntro, CMRoute2VondelPark_Text_NadalDefeat
	msgbox CMRoute2VondelPark_Text_NadalDefeat, MSGBOX_AUTOCLOSE
	end

CMRoute2VondelPark_EventScript_Federer::
	trainerbattle_single TRAINER_OUDERKERK_FEDERER, CMRoute2VondelPark_Text_FedererIntro, CMRoute2VondelPark_Text_FedererDefeat
	msgbox CMRoute2VondelPark_Text_FedererDefeat, MSGBOX_AUTOCLOSE
	end

@ Same gym-leader-style pattern as Ouderkerkerplas_EventScript_Jonas: the
@ event_script arg runs WolderPostBattle automatically, still locked, the
@ instant Wolder is defeated for the first time. Every later re-talk he's
@ already flagged defeated, so trainerbattle_single skips straight to the
@ AUTOCLOSE line below instead of re-running the HM hand-off.
CMRoute2VondelPark_EventScript_Wolder::
	trainerbattle_single TRAINER_OUDERKERK_WOLDER, CMRoute2VondelPark_Text_WolderIntro, CMRoute2VondelPark_Text_WolderDefeat, CMRoute2VondelPark_EventScript_WolderPostBattle
	msgbox CMRoute2VondelPark_Text_WolderDefeat, MSGBOX_AUTOCLOSE
	end

CMRoute2VondelPark_EventScript_WolderPostBattle::
	msgbox CMRoute2VondelPark_Text_WolderPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_VONDELPARK_BLOCKER
	release
	end

CMRoute2VondelPark_Text_TrinetteTriggerShout:
	.string "Trinette: Hey niet weggaan,\nRoland staat in de finale te\ltennissen!$"

CMRoute2VondelPark_Text_TrinetteRepeat:
	.string "Gezonde voeding, de mesoloog\nadviseert. Also, volg je mijn\lRoland anders even op\p"
	.string "Instargam?$"

CMRoute2VondelPark_Text_AndereFritsTriggerShout:
	.string "Andere Frits: Hey haal Woel\nniet uit zijn focus!$"

CMRoute2VondelPark_Text_AndereFritsIntro:
	.string "Hij pakt sowieso die finale$"

CMRoute2VondelPark_Text_AndereFritsRepeat:
	.string "Volgens mij is Mesologie\nhelemaal niet echt lol$"

CMRoute2VondelPark_Text_DjokoIntro:
	.string "Kosovo is toch gewoon deel van\nServie?$"

CMRoute2VondelPark_Text_DjokoDefeat:
	.string "Ik ga me echt niet inenten tegen\ncovid...$"

CMRoute2VondelPark_Text_NadalIntro:
	.string "Hola papi, voy a besar la reina$"

CMRoute2VondelPark_Text_NadalDefeat:
	.string "Honestly ik ben echt kneiter\nbalding lately ngl on god$"

CMRoute2VondelPark_Text_FedererIntro:
	.string "Ik ben de beste die ooit met\nballen heeft gespeeld$"

CMRoute2VondelPark_Text_FedererDefeat:
	.string "Gelukkig heb ik nog joods goud\nliggen$"

CMRoute2VondelPark_Text_WolderIntro:
	.string "Welkom op mijn baan, jou\nverslaan is een droom, maar niet\lDE droom$"

CMRoute2VondelPark_Text_WolderDefeat:
	.string "Ik ga maar op zoek naar Celia$"

CMRoute2VondelPark_Text_WolderPostBattle:
	.string "Geen vuistje voor mij vandaag.\nJe zoekt Cian? Lo weet sowieso\lwel waar hij is, die hebben nog\psamengewoond. Lo vindt je 100%\nin zijn kelder.$"
