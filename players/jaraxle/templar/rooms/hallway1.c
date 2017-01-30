#include "/players/jaraxle/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIW+"A hallway ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  The hallway within the castle is wide and spacious. The ceiling\n"+
"overhead has chandeliers hung to provide light, and windows spaced at\n"+
"intervals along the wall. Paintings framed in oak adorn the walls,\n"+
"each captivating and brilliantly created. Numerous battle scenes, as\n"+
"well as a painting of a stunning maiden of the purest light are dis-\n"+
"played. There are two doors, one on either side of the hallway, and\n"+
"the hallway itself continues to the north and south.\n";

items = ({
"paintings",
"Intricately painted scenes mainly depicting valorous battles",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/hallway2","north",
  "/players/jaraxle/templar/rooms/main","south",
"/players/jaraxle/templar/rooms/shop","east",
"/players/jaraxle/templar/rooms/armory","west",
});

}

init(){
 ::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

