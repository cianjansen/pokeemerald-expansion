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
