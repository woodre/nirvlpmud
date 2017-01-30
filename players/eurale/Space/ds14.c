#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Deep Space";
long_desc =
  "  You manage, slipping and sliding, to climb up this mountain of\n"+
  RED+"red stone"+NORM+".  Before you is a small dark hole that disappears into\n"+
  "the darkness.  The short climb to the top of this mound looks to\n"+
  "be both uninteresting and useless.\n";

items = ({
	"hole","A small hole, just a little larger than you",
});

dest_dir = ({
	"players/eurale/Space/ds15.c","enter",
	"players/eurale/Space/ds13.c","down",
});

}
