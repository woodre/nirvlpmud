#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The stairway is beginning to narrow here and it looks like\n"+
	"another tunnel goes off to the south.  It is getting lighter\n"+
	"the higher you climb.\n";

items = ({
	"stairway","Crudely cut steps of stone",
});

dest_dir = ({
	"players/eurale/Keep/k27.c","down",
	"players/eurale/Keep/k31.c","up",
	"players/eurale/Keep/k34.c","south",
});

}
