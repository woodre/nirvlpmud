#include "std.h"

object scotty;

extra_reset() {
   object weapon;
    if (!present("scotty")) {
	scotty = clone_object("obj/monster");
	call_other(scotty, "set_name", "scotty");
	call_other(scotty, "set_alias", "scotty");
	call_other(scotty, "set_short", "Scotty");
call_other(scotty,"set_long","Lt. Comm. Montgomery Scott\n");
	call_other(scotty, "set_wc", 17);
	call_other(scotty, "set_ac", 8);
call_other(scotty, "set_hp",350);
	call_other(scotty, "set_al", 60);
call_other(scotty, "set_level", 15);
	call_other(scotty, "set_aggressive", 0);
call_other(scotty, "set_chat_chance", 40);
call_other(scotty,"load_chat","Scotty says:Oh me poor little bairns!!!\n");
call_other(scotty,"load_chat","Scotty says:She`ll not take much more Captain!!!\n");
call_other(scotty,"load_chat","Scotty says:I estimate that it will take\n" +
               "8 days to fix the problem but I`ll do it in 2!!!\n");
	move_object(scotty, this_object());
	weapon = clone_object("obj/weapon");
	call_other(weapon, "set_name", "scottish broadsword");
	call_other(weapon, "set_alias", "sword");
	call_other(weapon, "set_short", "Scottish Broadsword");
	call_other(weapon, "set_class", 13);
	call_other(weapon, "set_weight", 3);
	call_other(weapon, "set_value", 500);
	move_object(weapon, scotty);
catch_tell(str) {
     string who,what,why;
     if (sscanf(str,"%s tells you: %s",who,what,why)!=3) return;
        tell_object(this_player(),"Scotty tells you: Aye prepare to come aboard.\n");
       move_object(this_player(),"players/rich/trans.c");
      }
     }
    }
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

ONE_EXIT("players/rich/lower/hall1d", "north",

         "Main Engineering",
         "This is main engineering,along the walls you\n" +
         "see the various components of the\n" +
         "impulse and warp drives and various other\n" +
         "systems such as the main anti-matter reactor.\n" +
         "To the north you see a hallway.\n",
         1)
realm(){return "enterprise";}
