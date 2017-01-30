#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/iceangel3.c"), this_object()); }
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"  Here the hallway turns and leads to the south and back to the west. The\n"+
"surrounding stone is finely crafted and shows no damage. Wall sconces\n"+
"provide adequate lighting as you make your way forward.\n";

items = ({
  "stone",
  "Whoever built this hallway and the surrounding rooms was a master craftsman\n"+
  "with endless skill",
  "sconces",
  "Trimmed in gold and beautiful in design, they provide light for your passage",
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r18.c","west",
  "/players/maledicta/ruins/rooms/r21.c","south"
});

}
