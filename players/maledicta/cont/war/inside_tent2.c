#include "/players/maledicta/ansi.h"
#define WAR "/players/maledicta/cont/war/war"

inherit "room/room";



reset(arg) {
if(!present("high_guard", this_object())){  
  move_object(clone_object("/players/maledicta/cont/war/high_templar.c"), this_object());
  move_object(clone_object("/players/maledicta/cont/war/high_templar.c"), this_object());
  }
if(WAR->query_total_goblins() > 10){
 if(!present("templar_scout", this_object())){  
  move_object(clone_object("/players/maledicta/cont/war/templar_scout.c"), this_object());
  }
 }
  if(arg) return;
set_light(1);
short_desc = HIG+"Templar "+HIW+"Command Tent"+NORM;
long_desc =
"  You stand within the beautiful Command Center of the Templar\n"+
"Knights.  All around hang strategic maps, with large bookcases\n"+
"lining the cloth walls.  A large table stands in the center of\n"+
"the room covered with scrolls and more maps. A flap leads out\n"+
"to the camp.\n";

items = ({
"maps",
"Several large color maps of the Realm of Nirvana and the West Coast",
"bookcases",
"Oak bookcases covered with books on strategy and war",
"walls",
"Bright green cloth walls",
"table",
"A large polished table with scrolls and maps covering it",
"scrolls",
"Scrolls with orders, supply recommendations, and messages",
"flap",
"A flap leading out to the camp", 
});

dest_dir = ({
  "/players/reflex/realms/coastline/pass_ent.c","out",
});
}
