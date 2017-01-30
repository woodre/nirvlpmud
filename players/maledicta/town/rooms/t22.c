#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  You find yourself in the northwest corner of the park. The defense wall\n"+
"is in clear view here, the trees only slightly blocking its base. The path\n"+
"leading through the park turns to the east, and also to the south leading\n"+
"into thicker foliage.\n";

items = ({
  "wall",
  "The towns defense wall. It glimmers with the power of an energy field\n"+
  "which lends it strength",
  "trees",
  "You find that the trees nearer the center are much taller here, as\n"+
  "compared to those near the wall. It is then you realize that the\n"+
  "smaller ones are younger, probably planted only a few years ago",
  "path",
  "A small brick path that is clean and well worn",
  "foliage",
  "It is green and healthy, grown much thicker near the center of the park",
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t23.c","east",
  "/players/maledicta/town/rooms/t20.c","south",
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	