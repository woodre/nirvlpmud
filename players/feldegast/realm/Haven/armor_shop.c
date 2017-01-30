#include "/players/feldegast/defines.h"
#include "../def.h"

inherit MYROOM;

object vendor;

reset(arg) {
  if (arg) return;
  if (!present("vendor")) {
    vendor=clone_object(PATH+"Haven/shpkpr1.c");
    move_object(vendor,this_object());
  }
  set_light(1);
  short_desc="Armor Shop";
  long_desc=
"     This is a small supply shop inside the coliseum.  The room is\n"+
"around ten meters square and filled with racks of armor and equipment.\n"+
"A low counter runs along the side of the shop, behind which is a large\n"+
"sign listing prices.\n";
  dest_dir=({
    PATH+"Haven/plaza.c","north",
  });
  items=({
    "sign",
"=================================================\n"+
"=    A leather gauntlet    -     75 coins       =\n"+
"=    A pair of boots       -    100 coins       =\n"+
"=    A green cloak         -    100 coins       =\n"+
"=    A crystal amulet      -    100 coins       =\n"+
"=    A plumed helmet       -    125 coins       =\n"+
"=    A steel shield        -    200 coins       =\n"+
"=    A suit of scale mail  -    700 coins       =\n"+
"=    A Quarterstaff        -   1000 coins       =\n"+
"=================================================\n",
    "counter","A low wooden counter",
    "racks","Look, but don't touch"
  });
}
query_no_fight() {
  return 1;
}
    
