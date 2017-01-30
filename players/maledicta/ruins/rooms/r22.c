#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int manes;
reset(arg) {
  if(!present("archangel")){
   move_object(clone_object("/players/maledicta/ruins/mobs/shadowangel.c"), this_object());}
 if(!present("shadowmane")){
  for(manes = 0; manes < 3;  manes++) {
  move_object(clone_object("/players/maledicta/ruins/mobs/shadowmane.c"), this_object());
   }  
}


  
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"  This room looks to once have been a war room. A large map carved in\n"+
"stone stands against one wall. The rest of the room looks to have been\n"+
"burned and mutilated as badly as the hallway before it. An opening in\n"+
"the ceiling reveals the sky beyond and a torrent of dark clouds whipping\n"+
"by. This room has the feel of evil about it.\n";

items = ({
  "map",
  "Looking closely you see that the map shows detailed elements of the\n"+
  "land beyond",
  "wall",
  "It is burned badly and cracked",
  "sky",
  "Dark and foreboding, you wonder what could have such an effect on the\n"+
  "weather",
  "clouds",
  "They are dark and ugly, allowing very little light to filter through",
  "opening",
  "Too small to climb through, it seems to have been a result of damage\n"+
  "suffered by the building",
  "ceiling",
  "It is broken and partially torn down in multiple places"
  
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r21.c","west",
});

}
