#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object guards;

reset(arg) {
if(!present("high_guard", this_object())){
  move_object(clone_object("/players/maledicta/templar/mobs/high_templar.c"), this_object());
  }
  if(arg) return;
set_light(1);

short_desc = "a hallway";
long_desc =
"  Here the hallway opens into a large room. Pillars stand in each of\n"+
"the corners, lending support to the ceiling overhead. The main council\n"+
"chambers stand to the north, with the main training hall to the east.\n"+
"A small dark passage leads to the west, a chill wind leading outward\n"+
"from it. The hallway continues to the south.\n";
move_object(clone_object("/players/maledicta/templar/mobs/high_templar.c"), this_object());
items = ({
"pillars",
"Stone pillars that support the ceiling overhead",
"passage",
"A very dark passage leading further into the west section of the\n"+
"castle",
});

dest_dir = ({
  "/players/maledicta/templar/rooms/adv_inner","north",
  "/players/maledicta/templar/rooms/hallway1","south",
  "/players/maledicta/templar/rooms/adv_guild","east",
  "/players/maledicta/templar/rooms/dark_hall","west"
});

}


init(){ 
  ::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }
