#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "a hallway";
long_desc =
"  This is a long hallway.  Paintings and banners line its entire\n"+
"length.  Small niches can be found along the walls, each containing\n"+
"some small work of art. To the east is the main dining hall, with\n"+
"the hall continuing to the north and south. A doorway leads west\n"+
"to the tower.\n";

items = ({
"paintings",
"Large paintings depicting valorious deeds and great battles",
"banners",
"Banners of the Templar order. Each is made of white fabric with\n"+
"a large red cross upon its surface",
"niches",
"Small openings in the wall, each with some form of art within",
"art",
"Small statues and old exquisite weaponry and armor",
});

dest_dir = ({
  "/players/maledicta/templar/rooms/hallway2","north",
  "/players/maledicta/templar/rooms/main","south",
"/players/maledicta/templar/rooms/feast_hall","east",
"/players/jaraxle/templar/rooms/tower", "west",
});

}

init(){
 ::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

