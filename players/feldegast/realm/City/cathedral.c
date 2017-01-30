/*
File: cathedral.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  A cathedral where you can get resurrected.
*/

#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Builder's Cathedral";
  long_desc=
    "  For centuries this cathedral has stood against the test of time,\n"+
    "through good times and bad.  At the moment, judging from the rich\n"+
    "decorations, you believe times are well for the church.  A golden\n"+
    "hammer upon the altar indicates that this cathedral is dedicated to\n"+
    "Danteles, known as The Builder.\n";
  items=({
  });
  dest_dir=({
    PATH+"marble3","south"
  });
}   
init() {
  ::init();
  add_action("cmd_pray","pray");
}
cmd_pray() {
  if(TP->query_ghost()) {
    write("You feel The Builder's blessing upon you.\n");
    say("A feeble shade coalesces into a solid form, sending a shiver\n"+
        "up your spine.\n");
    TP->remove_ghost();
    return 1;
  }
  write("You kneel in front of the altar and whisper a prayer to The Builder,\n"+
        "god of blacksmiths, artists, and creators of all kinds.\n");
  say(TPN+" kneels in front of the altar and whispers a prayer.\n");
  return 1;
}
