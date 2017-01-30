#include "def.h"
#include "/players/feldegast/defines.h"

inherit ROOM;


reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="The Coliseum's Foyer";
  long_desc=
"     This is the main entrance to Nirvana's coliseum.  It is a large\n"+
"spartan room with a low ceiling and a few torches along the walls.  A\n"+
"ramp to the north leads further down into the arena, while a staircase\n"+
"leads up into the stands.  A sign points west towards the sparring arena\n"+
"and another one points east towards the coliseum's stores.  There is a\n"+
"board here with arena notices.\n";
  items=({
    "ramp","A steep ramp leading further down into the coliseum where fights are negotiated",
    "torches","The torches brighten the room a little, but produce a great deal of\noily smoke",
    "stairs","The steep stairs lead up into the coliseum's stands",
    "board","It is a neat board with postings of the arena matches",
  });
  dest_dir=({
    PATH+"inner.c", "north",
    PATH+"spar_entry.c","west",
    "/players/feldegast/arena/rooms/crtyard","east",
    "/players/feldegast/arena/rooms/office","northeast",
    "/players/feldegast/shrine","out",
    "/players/feldegast/arena/rooms/stands1","up"
  });
}
query_no_fight() {
  return 1;
}
init() {
  ::init();
  add_action("read","read");
  add_action("down","down");
}
read(arg) {
  if(arg=="board" || arg=="notice" || arg=="notices") {
    tail("/players/feldegast/log/arena.log");
    return 1;
  }
}
down() {
  this_player()->move_player("down#players/feldegast/arena/rooms/recovery");
  return 1;
}
