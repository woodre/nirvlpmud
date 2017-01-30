#include "std.h"
object ogre;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
    if (!ogre || !living(ogre)) {
        object treasure;
        ogre = clone_object("obj/monster");
	call_other(ogre, "set_name", "small ogre");
	call_other(ogre, "set_alias", "ogre");
	call_other(ogre, "set_level", 4);
        call_other(ogre, "set_wc", 11);
        call_other(ogre, "set_ac", 4);
	call_other(ogre, "set_al", -100);
	call_other(ogre, "set_aggressive", 1);
	call_other(ogre, "set_short", "An ogre");
	call_other(ogre, "set_long", "A small ogre is here.\n");
	move_object(ogre, this_object());
        treasure = clone_object("obj/treasure");
        call_other(treasure, "set_id", "ruby");
        call_other(treasure, "set_alias", "gem");
        call_other(treasure, "set_short", "A small ruby");
        call_other(treasure, "set_weight", 1);
        call_other(treasure, "set_value", 150);
        move_object(treasure, ogre);
    }
}

THREE_EXIT("players/morgar/hills","north",
	 "players/morgar/cave","down",
	 "players/morgar/mountain","up",
         "Rolling hills",
         "You are in some rolling hills.  Above you, the hills\n" +
         "give way to mountains.   To the north you can see\n" +
         "a grassy field, while the hills continue in the other\n" +
         "directions.\n", 1)

