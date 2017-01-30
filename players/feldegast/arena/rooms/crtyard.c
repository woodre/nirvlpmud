#include "/players/feldegast/defines.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  move_object(clone_object("/players/feldegast/obj/healsign.c"),this_object());
  if (!present("vendor")) {
    move_object(clone_object("/players/feldegast/mon/vendor.c"),this_object());
  }

  short_desc="The Coliseum";
  long_desc=
"     This is a small courtyard in Nirvana's coliseum.  To the\n"+
"north is a small lounge for gladiators to relax and heal in.  To\n"+
"the south is an armour and equipment shop.  To the east is a\n"+
"pawn shop.\n";
  dest_dir=({
    "/players/feldegast/arena/rooms/lounge","north",
    "/players/feldegast/arena/rooms/foyer","west",
    "/players/feldegast/arena/rooms/shop","south",
    "/players/feldegast/arena/rooms/geneshop","east"
  });
  set_light(1);
}
query_no_fight() {
  return 1;
}
    

void init() {
  ::init();
  add_action("save_me","save_me");
}

int save_me(string str) {
  TP->save_me();
  return 1;
}
