#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "the hills";
long_desc =
"  This is a small winding path that leads through the base\n"+
"of the valley of hills. The path leads to the north and then\n"+
"up the face of the mountain, or to the south and further into\n"+
"the hills.\n";  

items = ({
  "path",
  "A winding path that leads to the mountain or into the hills",
  "mountain",
  "A large mountain that is part of a long range",
  "range",
  "A long mountain range that extends from the east to west",
  "hills",
  "Steep hills that fill the valley",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r4.c","north",
  "/players/maledicta/path/rooms/r6.c", "south",
});

}


