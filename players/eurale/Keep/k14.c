#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The tunnel here has much better lighting, almost as if it \n"+
	"were leading to some place special.  The torches are larger\n"+
	"and there are more of them and you can hear a hissing kind of\n"+
	"of noise up ahead.\n";

items = ({
	"floor","Solid rock and smooth",
	"torches","Wooden handles with lighted, burning ends",
});

dest_dir = ({
	"players/eurale/Keep/k13.c","north",
	"players/eurale/Keep/k15.c","south",
});

}

init() {
  ::init();
  add_action("listen","listen");
}

listen(str) {
if(!str || str == "hissing") {
  write("The sound is too far off to make it out clearly.\n");
  return 1; }
}
