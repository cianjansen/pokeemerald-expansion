Limburg_Pokemart_MapScripts::
	.byte 0

@ Same as AmsterdamZuidMart_EventScript_Denise/_Pokemart, own copy for this mart.
Limburg_Pokemart_EventScript_Denise::
	lock
	faceplayer
	msgbox Limburg_Pokemart_Text_DeniseIntro, MSGBOX_DEFAULT
	pokemart Limburg_Pokemart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Limburg_Pokemart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_MAX_ELIXIR
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ESCAPE_ROPE
	pokemartlistend

Limburg_Pokemart_EventScript_Shopper::
	lock
	faceplayer
	msgbox Limburg_Pokemart_Text_Shopper, MSGBOX_DEFAULT
	release
	end

Limburg_Pokemart_Text_DeniseIntro:
	.string "Hey FRITS, wil je condies\n"
	.string "kopen?$"

Limburg_Pokemart_Text_Shopper:
	.string "In deze mart verkopen ze\n"
	.string "alleen maar Vlaai man$"
