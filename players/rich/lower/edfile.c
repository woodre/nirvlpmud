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
	call_other(picard, "set_aggressive", 0);
call_other(picard, "set_chat_chance", 40);
call_other(picard,"load_chat","Captain Picard says: I surrender!!!!\n");
call_other(picard,"load_chat","Captain Picard says: Engage!\n");
call_other(picard,"load_chat","Captain Picard says: make it so!\n");
call_other(picard,"load_chat","Captain Picard says: Guinan and I are REAL close!\n");
	move_object(picard, this_object());
	weapon = clone_object("obj/weapon");
	call_other(weapon, "set_name", "phaser");
	call_other(weapon, "set_alias", "phaser");
	call_other(weapon, "set_short", "phaser");
	call_other(weapon, "set_class", 16);
	call_other(weapon, "set_weight", 4);
	call_other(weapon, "set_value", 15000);
	move_object(weapon, picard);
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

ONE_EXIT("players/rich/lower/hall5d", "south",

         "The Battlebridge",
         "This is the Battlebridge,around the bridge you see the various staitions of\n" +
         "all of the departments of the ship,in the center you see tactical,the      \n" +
         "captain's chair,helm,and navigations.\n" +
         "To the south you see a hallway.\n",
         1)
