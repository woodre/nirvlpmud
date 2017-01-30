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
"   This is the southeast corner of the park. A path cuts through this small\n"+
"woodland area, leading north and west. Ahead you see the towns defense wall\n"+
"through the trees canopies. Tall and short trees stand to either side of the\n"+
"path and spread out deeper into the park.\n";

items = ({
  "path",
  "A small brick path that leads through the small park",
  "wall",
  "The towns defense wall. It glimmers with the power of an energy field that\n"+
  "strengthens it",
  "canopies",
  "Green and full, you can barely see through them. In a few spots you can\n"+
  "barely make out the towns defense wall",
  "trees",
  "Ranging from tall to small in size, each is very healthy and full",
});

dest_dir = ({
  "/players/maledicta/town/rooms/t23.c","north",
  "/players/maledicta/town/rooms/t20.c","west",
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	