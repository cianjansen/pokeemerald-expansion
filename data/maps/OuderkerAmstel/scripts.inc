OuderkerAmstel_MapScripts::
	.byte 0

@ See Ouderkerk/scripts.inc for the shared Common_EventScript_BikeBlocker*
@ logic these hand off to.
OuderkerAmstel_EventScript_BikeBlockerTalk::
	setvar VAR_0x8008, LOCALID_OUDERKER_AMSTEL_BIKE_BLOCKER
	goto Common_EventScript_BikeBlockerTalk
	end

OuderkerAmstel_EventScript_BikeBlockerTrigger::
	setvar VAR_0x8008, LOCALID_OUDERKER_AMSTEL_BIKE_BLOCKER
	goto Common_EventScript_BikeBlockerTrigger
	end

OuderkerAmstel_EventScript_JonasHouseSign::
	msgbox OuderkerAmstel_Text_JonasHouseSign, MSGBOX_SIGN
	end

OuderkerAmstel_EventScript_CasHouseSign::
	msgbox OuderkerAmstel_Text_CasHouseSign, MSGBOX_SIGN
	end

OuderkerAmstel_EventScript_MargrietHouseSign::
	msgbox OuderkerAmstel_Text_MargrietHouseSign, MSGBOX_SIGN
	end

OuderkerAmstel_EventScript_TownSign::
	msgbox OuderkerAmstel_Text_TownSign, MSGBOX_SIGN
	end

OuderkerAmstel_Text_JonasHouseSign:
	.string "Casa di Michel, en ook\n"
	.string "Marieke, en Jonas, oh ja\l"
	.string "natuurlijk ook nog Sara,\p"
	.string "Oh en Josh, en waarom niet\n"
	.string "ook KitoKito4$"

OuderkerAmstel_Text_CasHouseSign:
	.string "Cas' bescheiden huis$"

OuderkerAmstel_Text_MargrietHouseSign:
	.string "Mama Margriet woont hier$"

OuderkerAmstel_Text_TownSign:
	.string "Ouderkerk a/d Amstel.\n"
	.string "Als je geen Porsche hebt\l"
	.string "ben je arm.$"
