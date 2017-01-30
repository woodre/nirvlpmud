#include "/players/jaraxle/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("board", this_object())){
  move_object(clone_object("players/boltar/templar/items/sponsorboard"),this_object());
  }
  if(arg) return;
set_light(1);

short_desc = HIW+"Recruitment Hall ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  The small chambers have little decoration. There is a small table\n"+
"with a vase of beautiful flowers pushed against the northern wall,\n"+
"and a window opened to the gardens just outside the castle walls.\n"+
"A circular rug covers much of the floor, bringing a warmth to the\n"+
"room.\n";

items = ({
"walls",
"Plain stone walls",
"window",
"A small window that looks out over the plains",
"stone",
"A simple stone that is well crafted",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/nrecruit","west",
});
}

init(){ 
  ::init();
/*
   this_player()->set_fight_area();
*/
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }


query_board() {
return present("board",this_object());
}
