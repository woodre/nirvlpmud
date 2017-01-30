inherit "room/room";
#include <ansi.h>

reset(arg){

    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Clearing)");
    long_desc=
 "You are at the northern edge of the clearing in the Darkenwood. A stone\n"+
 "wall rises from the ground to mark the northern border here, its dark\n"+
 "gray stone a cold thought of what might lie within. A large cave mouth\n"+
 "beckons you inwards.\n";

items=({
 "cave", "A cave leading into darkness. Perhaps you should go check it out",
 "woods", "The Darkenwood is a dangerous place, where humanoids and\n"+
          "other nasty creatures stalk about in the night",
 "stone", "The dark gray stone of the outcropping is cold to the touch,\n"+
          "and gives to clues as to its origins.\n",
 "wall", "A wall of stone rises out of the ground, blocking any further\n"+
         "movement northwards.\n",
 });


dest_dir=({
 "/players/daranath/clearing/clear8.c","south",
 "/players/daranath/clearing/clear9.c","west",
 "/players/daranath/clearing/cave1.c","enter",
           });
        }
        }
