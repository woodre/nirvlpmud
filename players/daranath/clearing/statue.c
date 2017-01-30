#include <ansi.h>
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Clearing)");
    long_desc=
 "The clearing within the Darkenwood spreads all about. Somewhat centered\n" +
 "within the area of the clearing is a large dark grey statue. A pair of\n"+
 "wolves are chasing a stagg across the base of the statue. Nothing else\n"+
 "is apparent about the statue itself.\n";

items=({
 "clearing", "The clearing opens up here within the darkness of the\n"+
             "woods, making it seem out of place. A small outcropping\n"+
             "of rock rises up in the northeast corner of the clearing",
 "woods", "The Darkenwood is a dangerous place, where humanoids and\n"+
          "other nasty creatures stalk about in the night",
 "statue", "The statue in the center of the clearing shows a scene of\n"+
           "a large Stagg running from a pack of wolves. The statue has\n"+
           "a natural sort of beauty about it, unlike the Darkenwood all\n"+
           "about it",
 });


dest_dir=({
 "/players/daranath/clearing/clear1.c","south",
 "/players/daranath/clearing/clear3.c","west",
 "/players/daranath/clearing/clear7.c","east",
 "/players/daranath/clearing/clear5.c","north",
 "/players/daranath/clearing/clear2.c","southwest",
 "/players/daranath/clearing/clear4.c","northwest",
 "/players/daranath/clearing/clear8.c","northeast",
 "/players/daranath/clearing/clear6.c","southeast",
           });
        }
        }
