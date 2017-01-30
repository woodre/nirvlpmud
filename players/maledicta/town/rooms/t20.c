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
"   This is the Derellia IV park. Looking around you notice that the towns\n"+
"inhabitants have spared the small patch of woods here, even allowed it to\n"+
"thrive within the confines of the defense wall.  All around are beautiful\n"+
"trees, small shrubs, and foliage. A small path stretches out before you\n"+
"leading north and east deeper into the park and south to the road that\n"+
"encirles the town. \n";

items = ({
  "trees",
  "Ranging from tall to short, some of the trees that stand around you are\n"+
  "obviously from other parts of the world. Each are beautiful and well\n"+
  "cared for",
  "shrubs",
  "Most of these shrubs have been planted by the caring folk of Derellia,\n"+
  "each trimmed lovingly to perfection",
  "foliage",
  "Fallen leaves and small plants, they cover the parks ground everywhere\n"+
  "you look, lending a natural look to the area",
  "path",
  "A small path that has been well cared for, it leads northward into the\n"+
  "park and back to the south and the town",
  "road",
  "A well cared for street that is made of stone. It seems to be cleaned\n"+
  "regularly",
   
});

dest_dir = ({
  "/players/maledicta/town/rooms/t22.c","north",
  "/players/maledicta/town/rooms/t21.c","east",
  "/players/maledicta/town/rooms/t13.c","south"
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	