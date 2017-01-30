#include "../def.h"
inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Cathedral of Haven";
  long_desc=
"  For centuries this cathedral has stood against the test of time,\n"+
"through good times and bad.  At the moment, judging from the rich\n"+
"decorations, you believe times are well for the church.  A golden\n"+
"scale upon the altar indicates that this cathedral is dedicated to\n"+
"Danteles, god of Justice and Balance.\n";
  items=({
  });
  dest_dir=({
    PATH+"Haven/town_square","south"
  });
}   
init() {
  ::init();
  add_action("cmd_pray","pray");
}
cmd_pray() {
  if(TP->query_ghost()) {
    write("You feel Danteles' blessing upon you.\n");
    say("A feeble shade coalesces into a solid form, sending a shiver\n"+
        "up your spine.\n");
    TP->remove_ghost();
    return 1;
  }
  write("You kneel in front of the altar and whisper a prayer to Dantles,\n"+
        "god of Justice and Balance.\n");
  say(TPN+" kneels in front of the altar and whispers a prayer.\n");
  return 1;
}
