#include "DEFS.h"
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "The Abyss";
long_desc =
  "  You step from the darkness into a strange space.  All around you\n"+
  "is stark "+HIW+"whiteness"+NORM+".  The fear you've been experiencing is much less\n"+
  "here but it never fully leaves you.  Is your mind playing tricks on\n"+
  "you?  You steel yourself against the scream welling up inside of YOU!\n";

}

init() {
  ::init();
  add_action("east","east");
}

east() {
  TP->move_player("darkness#players/eurale/Abyss/a2.c");
  return 1; }

realm() { return "NT"; }
