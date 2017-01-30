#include "/room/room.h"
#undef EXTRA_RESET

object dragon;

#define EXTRA_RESET\
    if (!dragon || !living(dragon)) {\
	object treas;\
	dragon = clone_object("obj/monster");\
	call_other(dragon, "set_name", "dragon");\
	call_other(dragon, "set_level", 17);\
	call_other(dragon, "set_al", -900);\
	call_other(dragon, "set_short", "A generic creature wearing a T-shirt that reads DRAGON");\
	call_other(dragon, "set_wc", 25);\
	call_other(dragon, "set_ac", 4);\
	treas = clone_object("obj/treasure");\
	call_other(treas, "set_id", "sapphire");\
	call_other(treas, "set_alias", "stone");\
	call_other(treas, "set_short", "A generic stone with a tag that reads SAPPHIRE");\
	call_other(treas, "set_value", 250);\
	move_object(treas, dragon);\
	treas = clone_object("obj/treasure");\
	call_other(treas, "set_id", "diamond");\
	call_other(treas, "set_alias", "stone");\
	call_other(treas, "set_short", "A generic stone with a tag that reads DIAMOND");\
	call_other(treas, "set_value", 250);\
	move_object(treas, dragon);\
	move_object(dragon, this_object());\
    }
ONE_EXIT("/players/doctor/CASTLE/tunnel28", "west",
	 "Generic dead end",
	 "Generic dead end.\n", 0)
