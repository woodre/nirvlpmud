#include <ansi.h>
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Clearing)");
    long_desc=
 "You are at the northern edge of the clearing in the Darkenwood. A stone\n"+
 "wall rises from the ground to mark the northern border here, with a dark\n"+
 "cave opening to the east of your position.\n";

items=({
 "cave", "A cave leading into darkness. Perhaps you should go check it out",
 "woods", "The Darkenwood is a dangerous place, where humanoids and\n"+
          "other nasty creatures stalk about in the night",
 "wall", "The wall of stone rises up to block any further passage north",
 "stone", "The stone is dark grey and cold to the touch",
 });


dest_dir=({
 "/players/daranath/clearing/clear5.c","south",
 "/players/daranath/clearing/clear10.c","east",
           });
        }
        }
