AmsterdamCentrumLoHuis_MapScripts::
	.byte 0

AmsterdamCentrumLoHuis_EventScript_Ales::
	trainerbattle_single TRAINER_ALES, AmsterdamCentrumLoHuis_Text_AlesIntro, AmsterdamCentrumLoHuis_Text_AlesDefeat
	msgbox AmsterdamCentrumLoHuis_Text_AlesDefeat, MSGBOX_AUTOCLOSE
	end

AmsterdamCentrumLoHuis_EventScript_MarcosJuan::
	trainerbattle_single TRAINER_MARCOS_JUAN, AmsterdamCentrumLoHuis_Text_MarcosJuanIntro, AmsterdamCentrumLoHuis_Text_MarcosJuanDefeat
	msgbox AmsterdamCentrumLoHuis_Text_MarcosJuanDefeat, MSGBOX_AUTOCLOSE
	end

@ Passing an event_script to trainerbattle_single (4th arg) makes it run that
@ script automatically, still locked, the instant Lo is defeated for the
@ first time - same pattern as Ouderkerkerplas_EventScript_JonasPostBattle,
@ needed so the TM hand-off fires right after the win instead of requiring a
@ second, separate re-talk. See CLAUDE.md's trainerbattle_single rule.
AmsterdamCentrumLoHuis_EventScript_Lo::
	trainerbattle_single TRAINER_LO, AmsterdamCentrumLoHuis_Text_LoIntro, AmsterdamCentrumLoHuis_Text_LoDefeat, AmsterdamCentrumLoHuis_EventScript_LoPostBattle
	msgbox AmsterdamCentrumLoHuis_Text_LoDefeat, MSGBOX_AUTOCLOSE
	end

@ Only reached automatically on the first win (see comment above), once
@ control has returned to the overworld (DefeatText already played during
@ the battle-end transition itself). Every later re-talk, Lo is already
@ flagged defeated, so trainerbattle_single skips straight to the AUTOCLOSE
@ line in AmsterdamCentrumLoHuis_EventScript_Lo instead of running this again.
AmsterdamCentrumLoHuis_EventScript_LoPostBattle::
	msgbox AmsterdamCentrumLoHuis_Text_LoPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_TM_TOXIC
	setflag FLAG_LO_BEATEN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

AmsterdamCentrumLoHuis_EventScript_Gracia::
	lock
	faceplayer
	goto_if_set FLAG_LO_BEATEN, AmsterdamCentrumLoHuis_EventScript_GraciaAfterLo
	msgbox AmsterdamCentrumLoHuis_Text_GraciaBeforeLo, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumLoHuis_EventScript_GraciaAfterLo::
	msgbox AmsterdamCentrumLoHuis_Text_GraciaAfterLo, MSGBOX_DEFAULT
	release
	end

AmsterdamCentrumLoHuis_Text_AlesIntro:
	.string "ALES: Ik heb een nieuw dieet\n"
	.string "waardoor ik unbeatable ben$"

AmsterdamCentrumLoHuis_Text_AlesDefeat:
	.string "ALES: Het komt sowieso door de\n"
	.string "gluten man$"

AmsterdamCentrumLoHuis_Text_MarcosJuanIntro:
	.string "MARCOS JUAN: Yo check wat ik heb\n"
	.string "gekocht op IBOOD vandaag$"

AmsterdamCentrumLoHuis_Text_MarcosJuanDefeat:
	.string "LAS MALVINAS SON ARGENTINAS\n"
	.string "LAS MALVINAS SON ARGENTINAS\n"
	.string "LAS MALVINAS SON ARGENTINAS\l"
	.string "\p"
	.string "LAS MALVINAS SON ARGENTINAS\n"
	.string "LAS MALVINAS SON ARGENTINAS\n"
	.string "LAS MALVINAS SON ARGENTINAS\l"
	.string "\p"
	.string "LAS MALVINAS SON ARGENTINAS\n"
	.string "LAS MALVINAS SON ARGENTINAS$"

@ Same "rough script" said twice: once in kana-only Japanese ({JPN}/{ENG}
@ switch the font/glyph table mid-string, see EXT_CTRL_CODE_JPN/ENG in
@ src/text.c - no kanji glyphs exist in charmap.txt, hiragana/katakana only),
@ then the Dutch original verbatim. This engine feature has no other user in
@ this hack yet - if the kana renders wrong in-game, check line-wrap length
@ first (Japanese glyphs are roughly double-width vs the Latin font).
AmsterdamCentrumLoHuis_Text_LoIntro:
	.string "{JPN}ニーハオ。こんにちは。\n"
	.string "もしもし。ロレンツォです。\n"
	.string "わたしのアニメちかしつへ\l"
	.string "\p"
	.string "ようこそ。\n"
	.string "ちかしつじゃないよ。\n"
	.string "オカリンとよんでね。\l"
	.string "\p"
	.string "きみのバナナを\n"
	.string "ムースにするほうほうを\n"
	.string "おしえるよ。{ENG}\l"
	.string "\p"
	.string "LO: Nihao, Konichiwa, Moshi Moshi\n"
	.string "Lorenzo-des. Welkom in mijn\n"
	.string "Anime-Souterrain (het is geen\l"
	.string "\p"
	.string "kelder hoorrrr). Noem me Okarin\n"
	.string "hoe ik je banaan verander in\l"
	.string "mush$"

@ Shown during the battle-end transition itself, the instant Lo is beaten.
AmsterdamCentrumLoHuis_Text_LoDefeat:
	.string "Als ik blijf Practicen zal ik To\n"
	.string "Winnen!!$"

@ Shown separately, back on the overworld, by
@ AmsterdamCentrumLoHuis_EventScript_LoPostBattle - not part of the
@ battle-end DefeatText above.
AmsterdamCentrumLoHuis_Text_LoPostBattle:
	.string "Nu ga ik troost zoeken in mijn\n"
	.string "Mayuri body pillow...\l"
	.string "\p"
	.string "Cian? Ik was laatst met hem in\n"
	.string "Grijpskerk bij Hibob, daar zal ie\l"
	.string "wel zijn$"

AmsterdamCentrumLoHuis_Text_GraciaBeforeLo:
	.string "GRACIA: Heeyyyyy FRITS, wat zie\n"
	.string "jij er goed uit knappert.\p"
	.string "Lo is daar achterin, als ie\n"
	.string "verliest ga ik zijn Skyrim saves\l"
	.string "van de XBOX wipen$"

AmsterdamCentrumLoHuis_Text_GraciaAfterLo:
	.string "GRACIA: Kom je later nog even\n"
	.string "langs als MARCOS JUAN weg is?$"
