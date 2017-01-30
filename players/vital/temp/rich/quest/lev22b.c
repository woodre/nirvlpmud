#include "std.h"

object picard;

extra_reset() {
   object weapon;
    if (!present("picard")) {
	picard = clone_object("obj/monster");
	call_other(picard, "set_name", "captain picard");
	call_other(picard, "set_alias", "picard");
	call_other(picard, "set_level", 18);
	call_other(picard, "set_short", "Captain Picard");
call_other(picard,"set_long","Captain Jean-Luc Picard\n");
	call_other(picard, "set_wc", 20);
	call_other(picard, "set_ac", 6);
call_other(picard, "set_hp",550);
	call_other(picard, "set_al", 500);
	call_other(picard, "set_aggressive", 1);
call_other(picard, "set_chat_chance", 40);
call_other(picard,"load_chat","I surrender!!!!\n");
call_other(picard,"load_chat","Engage!\n");
call_other(picard,"load_chat","make it so!\n");
call_other(picard,"load_chat","Guinan and I are REAL close!\n");
	move_object(picard, this_object());
	weapon = clone_object("obj/weapon");
	call_other(weapon, "set_name", "phaser");
	call_other(weapon, "set_alias", "phaser");
	call_other(weapon, "set_short", "phaser");
	call_other(weapon, "set_class", 12);
	call_other(weapon, "set_weight", 4);
	call_other(weapon, "set_value", 15000);
	move_object(weapon, picard);
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

FOUR_EXIT("players/rich/room2u", "south",
          "players/rich/quest/lev22c.c", "west",
          "players/rich/quest/lev22a.c", "north",
          "players/rich/quest/lev24a.c", "east",

         "The Battlebridge",
         "To the south is a hallway,\n" ,
         1)
realm(){return "NT";}
