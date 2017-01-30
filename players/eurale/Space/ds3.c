#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Deep Space";
long_desc =
  "  You have come to the edge of large "+RED+"crater"+NORM+".  It is dark and deep\n"+
  "but it appears that you might be able to enter it at this point.\n"+
  "A smoothness to the edge stands out in this outherwise jagged \n"+
  "world.\n";

items = ({
	"crater","A huge green hole about 30 feet wide",
	"edge","The ridge has been smoothed by use",
});

dest_dir = ({
	"players/eurale/Space/ds2.c","north",
	"players/eurale/Space/ds4.c","enter",
});

}
