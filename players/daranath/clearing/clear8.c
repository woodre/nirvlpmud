#include <ansi.h>
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Clearing)");
    long_desc=
 "The clearing within the Darkenwood spreads all about. The darkness of\n" +
 "the woods makes this area seem slightly smaller then it is, bringing\n" +
 "about a sense of security while you are here. A large stone fountain\n" +
 "stands southwest from here, while a stone outcropping rises from the\n"+
 "ground directly to the north.\n";

items=({
 "clearing", "The clearing opens up here within the darkness of the\n"+
             "woods, making it seem out of place. A small outcropping\n"+
             "of rock rises up in the northeast corner of the clearing",
 "stone", "An outcropping of stone rises up just to the north of\n"+
         "the clearing, a small cave mouth can be seen on its facing",
 "cave", "A cave leading into darkness. Perhaps you should go check it out",
 "woods", "The Darkenwood is a dangerous place, where humanoids and\n"+
          "other nasty creatures stalk about in the night",
 "fountain", "The stone fountain stands to the southwest from here",
 });


dest_dir=({
 "/players/daranath/clearing/statue.c","southwest",
 "/players/daranath/clearing/clear5.c","west",
 "/players/daranath/clearing/clear7.c","south",
 "/players/daranath/clearing/clear10.c","north",
           });
        }
        }
