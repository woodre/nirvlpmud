#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("sentry")) {
move_object(clone_object("players/eurale/Keep/NPC/sentry1"),TO); }
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The tunnel here has much better lighting, almost as if it \n"+
	"were leading to some place special.  The torches are larger\n"+
	"and there are more of them and you can hear a hissing kind of\n"+
	"of noise up ahead.  You can also make out a brighter tunnel as\n"+
	"you continue south.\n";

items = ({
	"floor","Solid rock and smooth",
	"torches","Wooden handles with lighted, burning ends",
});

dest_dir = ({
	"players/eurale/Keep/k14.c","north",
	"players/eurale/Keep/k16.c","south",
});

}

init() {
  ::init();
  add_action("listen","listen");
  add_action("south","south");
}

listen(str) {
if(!str || str == "hissing") {
  write("The hissing sounds a little like a fire.\n");
  return 1; }
}

south() {
if(present("sentry")) {
  write("The Sentry pokes you with a sharp talon and says: No one is\n"+
        "allowed beyond here without permission.  Be gone with you!\n");
  say("The sentry pokes "+capitalize(TPRN)+" with a sharp talon...\n");
  this_player()->heal_self(-15);
  return 1; }
else {
  this_player()->move_player("south#players/eurale/Keep/k16.c");
  return 1; }
}
