#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("golden_plates", this_object())){
move_object(clone_object("/players/maledicta/templar/eplate.c"), this_object());
}
if(!present("bulletin board", this_object())){
move_object(clone_object("/players/maledicta/hope/eboard.c"), this_object());
}

  if(arg) return;
set_light(1);
short_desc = RED+"Inner Sanctum of the Elite Guard"+NORM;
long_desc = 
"  You stand within the Inner Sanctum of the Templar\n"+
"Elite Guard. Here the Elite Knights come to post their\n"+
"deeds of Valor and discuss the tactics of battle. A\n"+
"hidden door leads to the east and back to the inner\n"+
"hall.\n"; 

items = ({
"walls",
"The walls are made from a beautiful white stone, bound by a glittering\n"+
"mortar.  Numerous holy symbols adorn each stone, binding and protecting\n"+
"the tower from harm",
"stone",
"A beautiful white stone",
"symbols",
"Small holy symbols etched into the stone",
"door",
"A stone leading to the inner hall",
});


dest_dir = ({
  "/players/maledicta/hope/rooms/hinner.c", "east",
});

}

no_hunter(){ return 1; }
