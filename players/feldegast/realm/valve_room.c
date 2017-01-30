#include "/players/feldegast/defines.h"
#include "def.h"

inherit ROOM;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Lock Cavern";
  long_desc=
"  A soft, phosphorescent glow barely lights this cavern's inky\n\
blackness.  A steady drip of water falls through the air and down\n\
into an ominous dark pit.  Above the pit is a complicated mechanism\n\
whose purpose you cannot gauge.  A rusty metal plate with a dwarven\n\
symbol on it is near the pit.\n";
  dest_dir=({
    PATH+"duh","down",
  });
}
void init() {
  ::init();
  add_action("cmd_place","place");
  add_action("cmd_place","use");
}
int cmd_place(string str) {
  notify_fail("Use what?\n");
  if(!str || str!="seal") {
    return 0;
  }
  if(!present("dwarven_valve_seal")) {
    write("You don't have that.\n");
    return 1;
  }
  write("You place the dwarven seal on the metal plate.\n");
  say(TPN+" places the dwarven seal on the metal plate.\n");
  call_out("open_valve",10);
  return 1;
}
void open_valve() {
  call_other(PATH+"caldera","set_puzzle",1);
  tell_room(this_object(),
"The great valve gates open above the pit and a waterfall streams\n\
down into the abyss.\n");
  long_desc=
"  A soft, phosphorescent glow barely lights this cavern's inky\n\
blackness.  A steady stream of water falls through the air and down\n\
into an ominous dark pit.  Above the pit is a complicated mechanism\n\
whose purpose you cannot gauge.  A rusty metal plate with a dwarven\n\
symbol on it is near the pit.\n";
  return;
} 
