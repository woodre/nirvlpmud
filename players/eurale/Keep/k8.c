#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The tunnel has narrowed at this point and is descending deeper\n"+
	"into the bowels of this huge Keep.  There is a pungent odor in\n"+
	"in the air as well.  The torches are providing less and less\n"+
	"light as the cave goes deeper and they get much farther apart.\n";

items = ({
	"torches","Wooden handles with lighted, burning ends",
});

dest_dir = ({
	"players/eurale/Keep/k4.c","up",
	"players/eurale/Keep/k9.c","down",
});

}

init() {
  ::init();
  add_action("smell","smell");
}

smell(str) {
int amt;
  if(!str) { write("What are you trying to smell?\n"); return 1; }
  if(str == "odor" || str == "pungent odor") {
  amt = 15 + random(20);
    write("You inhale... and the sting of this putrid air burns your\n"+
	  "nose and makes your eyes water.  It is the smell of rotting\n"+
	  "and decaying flesh.\n");
    this_player()->add_hit_point(-amt);
    return 1; }
}
