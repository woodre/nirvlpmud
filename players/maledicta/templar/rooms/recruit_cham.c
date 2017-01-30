#include "/players/maledicta/ansi.h"
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

short_desc = "Recruitment Hall "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  This is a small nondescript room.  The walls are made of a\n"+
"simple stone with a single window looking out.  A stairway\n"+
"leads down to the Inner Chamber.\n";

items = ({
"walls",
"Plain stone walls",
"window",
"A small window that looks out over the plains",
"stone",
"A simple stone that is well crafted",
"stairway",
"A narrow stairway that winds down to the Inner Chamber",
});

dest_dir = ({
  "/players/maledicta/templar/rooms/nrecruit","down",
});
}

init(){ 
  ::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }


query_board() {
return present("board",this_object());
}