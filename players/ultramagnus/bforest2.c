#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT\
       add_action("up","climb");
#undef EXTRA_INIT
#define EXTRA_INIT\
       add_action("west","west");
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
object tree, gollum;
       if(!present("tree")){
         tree=clone_object("players/ultramagnus/btree.c");
         move_object(tree, this_object());
       }
       if(!present("gollum")){
         gollum=clone_object("obj/monster.c");
        call_other(gollum, "set_name", "gollum");
        call_other(gollum, "set_alias", "gollum");
/* Changed from 18 to 12 to reflect stats - Snow */
        call_other(gollum, "set_level", 12);
        call_other(gollum, "set_short", "Gollum");
       call_other(gollum, "set_long", "A disgusting looking Monster with Large Green eyes and Green and Grey skin.\n" +
       "It is slightly larger than a hobbit.  It seems to be talking with itself!!\n");
        call_other(gollum, "set_wc", 15);
        call_other(gollum, "set_ac", 8);
/* Changed from 300 to work better with level -Snow 3/00 */
        call_other(gollum, "set_hp", random(40)+160);
        call_other(gollum, "set_al", -150);
       call_other(gollum, "set_aggressive", 0);
       call_other(gollum, "set_chat_chance", 35);
       call_other(gollum, "load_chat",
                     "Gollum says: Ahh...A Tiny Morsal for My Precious to Taste!\n");
       call_other(gollum, "load_chat",
                     "Gollum says: Will it taste Good My Precious...???\n");
      call_other(gollum, "load_chat",
                     "Gollum says: Where is Precious' Ring??!!\n");
       call_other(gollum, "load_chat",
                     "Gollum says: My Precious got That Ring for his Birthday...!!!\n");
       call_other(gollum, "load_chat",
                     "Gollum says: Will it taste Bitter???\n");
       call_other(gollum, "load_chat",
                     "Gollum says: The Baggins must Have it....!!!...\n");
       call_other(gollum, "load_chat",
              "Gollum thinks and begins to search in the grass.\n");
       move_object(gollum, this_object());
       }
}
TWO_EXIT("players/ultramagnus/bforest1.c", "east",
       "players/ultramagnus/bforest3.c", "north",
       "Shelter",
       "The Forest is very lively here.  You see many things that you've\n" +
       "never seen before.  Up above you see tiny people working and\n" +
       "picking fruit from the trees.  There is a shelter of sorts to the\n" +
       "West.  It is hidden behind some Blue trees.\n", 1)
up()
{
       call_other(this_player(), "move_player", "up#players/ultramagnus/bluetree.c");
       return 1;
}
west()
{
       if(present("gollum")){
              write("Gollum jumps in front of you and blocks your way!\n");
              write("Gollum says: No!...You just want Precious' Ring!!!\n");
              write("Gollum says: Only My Precious can have Ring!!!\n");
              return 1;
       }
       call_other(this_player(), "move_player", "west#players/ultramagnus/btrail.c");
       return 1;
}
