#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "room/room";


reset(arg) {
    if(!arg) 
  {
set_light(1);

short_desc = ""+HIY+"A Giant Sponge"+NORM+"";
long_desc =
"  You are inside what appears to be a "+HIY+"giant sponge"+NORM+".  There\n"+
"are many holes around you and you are curious as to where\n"+
"they lead.  All of the holes are dark except for one.  This\n"+
"hole is lit and from it you can hear the sounds of a wild\n"+
"beach and you can smell the soft scent of saltwater.\n";

add_listen("main", "You hear the faint sounds of birds and waves.");
add_smell("main", "You can faintly smell saltwater.");

items = ({
  "holes",
  "Many dark holes all around you leading to many different misterious places",
  "sponge", 
  "A strange sea creature that holds many misteries of the world",
    });

dest_dir = ({
  "/players/jamila/beach/beach1.c","beach",
  "room/farmroad3","out",
  });
  }
}
