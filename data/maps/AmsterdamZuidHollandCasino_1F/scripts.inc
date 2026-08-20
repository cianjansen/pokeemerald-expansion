AmsterdamZuidHollandCasino_1F_MapScripts::
	.byte 0

AmsterdamZuidHollandCasino_1F_EventScript_WinnerGiveEevee::
	lock
	faceplayer
	goto_if_set FLAG_GOT_CASINO_EEVEE, AmsterdamZuidHollandCasino_1F_EventScript_WinnerRepeat
	msgbox AmsterdamZuidHollandCasino_1F_Text_WinnerGiveEevee, MSGBOX_DEFAULT
	givemon SPECIES_EEVEE, 12
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, AmsterdamZuidHollandCasino_1F_EventScript_GaveEevee
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, AmsterdamZuidHollandCasino_1F_EventScript_GaveEevee
	goto Common_EventScript_NoMoreRoomForPokemon

@ Vaporeon/Jolteon/Flareon/Leafeon/Glaceon all evolve Eevee via a stone in
@ this build (see SPECIES_EEVEE's .evolutions in
@ src/data/pokemon/species_info/gen_1_families.h) - handing over all 5 here
@ so every stone-based Eeveelution is reachable right away. Espeon/Umbreon/
@ Sylveon evolve via friendship (+ time of day / a Fairy-type move for
@ Sylveon) instead, so there's no item for those - normal play covers them.
AmsterdamZuidHollandCasino_1F_EventScript_GaveEevee::
	msgbox AmsterdamZuidHollandCasino_1F_Text_ReceivedEevee, MSGBOX_DEFAULT
	additem ITEM_THUNDER_STONE
	additem ITEM_WATER_STONE
	additem ITEM_FIRE_STONE
	additem ITEM_LEAF_STONE
	additem ITEM_ICE_STONE
	msgbox AmsterdamZuidHollandCasino_1F_Text_ReceivedStones, MSGBOX_DEFAULT
	setflag FLAG_GOT_CASINO_EEVEE
	release
	end

AmsterdamZuidHollandCasino_1F_EventScript_WinnerRepeat::
	msgbox AmsterdamZuidHollandCasino_1F_Text_WinnerGiveEevee, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidHollandCasino_1F_EventScript_NftLoss::
	lock
	faceplayer
	msgbox AmsterdamZuidHollandCasino_1F_Text_NftLoss, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidHollandCasino_1F_EventScript_YourTurnToPay::
	lock
	faceplayer
	msgbox AmsterdamZuidHollandCasino_1F_Text_YourTurnToPay, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidHollandCasino_1F_EventScript_PaidForChips::
	lock
	faceplayer
	msgbox AmsterdamZuidHollandCasino_1F_Text_PaidForChips, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidHollandCasino_1F_EventScript_GambleGamble::
	lock
	faceplayer
	msgbox AmsterdamZuidHollandCasino_1F_Text_GambleGamble, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidHollandCasino_1F_EventScript_Patron1::
	lock
	faceplayer
	msgbox AmsterdamZuidHollandCasino_1F_Text_Patron1, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidHollandCasino_1F_EventScript_Patron2::
	lock
	faceplayer
	msgbox AmsterdamZuidHollandCasino_1F_Text_Patron2, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidHollandCasino_1F_EventScript_MaxBrundt::
	trainerbattle_single TRAINER_OUDERKERK_MAX_BRUNDT, AmsterdamZuidHollandCasino_1F_Text_MaxBrundtIntro, AmsterdamZuidHollandCasino_1F_Text_MaxBrundtDefeat
	msgbox AmsterdamZuidHollandCasino_1F_Text_MaxBrundtDefeat, MSGBOX_AUTOCLOSE
	end

AmsterdamZuidHollandCasino_1F_EventScript_KTaylor::
	trainerbattle_single TRAINER_OUDERKERK_K_TAYLOR, AmsterdamZuidHollandCasino_1F_Text_KTaylorIntro, AmsterdamZuidHollandCasino_1F_Text_KTaylorDefeat
	msgbox AmsterdamZuidHollandCasino_1F_Text_KTaylorDefeat, MSGBOX_AUTOCLOSE
	end

@ Same gym-leader-style pattern as Ouderkerkerplas_EventScript_Jonas: the
@ event_script arg runs TobiasPostBattle automatically, still locked, the
@ instant Tobias is defeated for the first time. Every later re-talk he's
@ already flagged defeated, so trainerbattle_single skips straight to the
@ AUTOCLOSE line below instead of re-running the reward.
AmsterdamZuidHollandCasino_1F_EventScript_Tobias::
	trainerbattle_single TRAINER_OUDERKERK_TOBIAS, AmsterdamZuidHollandCasino_1F_Text_TobiasIntro, AmsterdamZuidHollandCasino_1F_Text_TobiasDefeat, AmsterdamZuidHollandCasino_1F_EventScript_TobiasPostBattle
	msgbox AmsterdamZuidHollandCasino_1F_Text_TobiasRepeat, MSGBOX_AUTOCLOSE
	end

AmsterdamZuidHollandCasino_1F_EventScript_TobiasPostBattle::
	addmoney 999999, 0
	setflag FLAG_TOBIAS_BEATEN
	giveitem ITEM_TM_SHADOW_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox AmsterdamZuidHollandCasino_1F_Text_TobiasMatchaLatte, MSGBOX_DEFAULT
	release
	end

AmsterdamZuidHollandCasino_1F_Text_WinnerGiveEevee:
	.string "Ik heb kneiter dik gewonne,\n"
	.string "hier cadeautje$"

AmsterdamZuidHollandCasino_1F_Text_ReceivedEevee:
	.string "FRITS received an EEVEE!$"

AmsterdamZuidHollandCasino_1F_Text_ReceivedStones:
	.string "FRITS also received 5\n"
	.string "evolution stones!$"

AmsterdamZuidHollandCasino_1F_Text_Patron1:
	.string "Wat heeft die Gerrie toch een\n"
	.string "kutkop$"

AmsterdamZuidHollandCasino_1F_Text_Patron2:
	.string "Huh, ik had een perfect plan.\n"
	.string "Hoe kon dit fout gaan?$"

AmsterdamZuidHollandCasino_1F_Text_NftLoss:
	.string "Ik heb al m'n geld vergokt aan\n"
	.string "NFT's$"

AmsterdamZuidHollandCasino_1F_Text_YourTurnToPay:
	.string "Hey vriend volgens mij is het\n"
	.string "jouw beurt om te dokken$"

AmsterdamZuidHollandCasino_1F_Text_PaidForChips:
	.string "Jij betaalde deze ronde chips\n"
	.string "toch makker$"

AmsterdamZuidHollandCasino_1F_Text_GambleGamble:
	.string "GAMBLE GAMBLE KUTTT$"

AmsterdamZuidHollandCasino_1F_Text_MaxBrundtIntro:
	.string "MAX BRUNDT: Ik hoe vet veel\n"
	.string "van roelet$"

AmsterdamZuidHollandCasino_1F_Text_MaxBrundtDefeat:
	.string "MAX BRUNDT: Volgende keer doe\n"
	.string "ik jou op root$"

AmsterdamZuidHollandCasino_1F_Text_KTaylorIntro:
	.string "K. TAYLOR: Ik probeer geld te\n"
	.string "verdienen voor Jade-Anna$"

AmsterdamZuidHollandCasino_1F_Text_KTaylorDefeat:
	.string "K. TAYLOR: Dat wordt geen\n"
	.string "borstvergroting dit jaar$"

AmsterdamZuidHollandCasino_1F_Text_TobiasIntro:
	.string "TOBIAS: Ik ben Twabba, de\n"
	.string "slachter der high rollers.\p"
	.string "Terwijl jij kaarten telt,\n"
	.string "tel ik m'n stack$"

AmsterdamZuidHollandCasino_1F_Text_TobiasDefeat:
	.string "TOBIAS: Rien ne va plus, no\n"
	.string "more bets, hier heb je al\l"
	.string "mijn cash.$"

AmsterdamZuidHollandCasino_1F_Text_TobiasRepeat:
	.string "TOBIAS: Ik ga chillen met\n"
	.string "Ziyech, laters$"

AmsterdamZuidHollandCasino_1F_Text_TobiasMatchaLatte:
	.string "TOBIAS: Nu kan je sowieso\n"
	.string "minstens een Matcha Latte met\l"
	.string "Mango kopen$"
