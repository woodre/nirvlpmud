#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("eurale_sentry_2")) {
move_object(clone_object("players/eurale/Keep/NPC/sentry2"),TO); }
if(!present("eurale_sentry_3")) {
move_object(clone_object("players/eurale/Keep/NPC/sentry3"),TO); }
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The tunnel here has much better lighting, almost as if it \n"+
	"were leading to some place special.  The torches are larger\n"+
	"and there are more of them and you can hear a hissing kind of\n"+
	"of noise up ahead.  The tunnel is beginning to slope down once\n"+
	"again and the brightness from the tunnel further down is very\n"+
	"disturbing.\n";

items = ({
	"floor","Solid rock and smooth",
	"torches","Wooden handles with lighted, burning ends",
});

dest_dir = ({
	"players/eurale/Keep/k15.c","north",
	"players/eurale/Keep/k17.c","down",
});

}

init() {
  ::init();
  add_action("listen","listen");
  add_action("down","down");
}

listen(str) {
if(!str || str == "hissing") {
  write("It sounds very much like a roaring fire now.\n");
  return 1; }
}

down() {
if(present("disir")) {
  write("The Imperial Disir freezes you with his stare....\n");
  say(capitalize(TPRN)+" is frozen in place by the Disir's stare....\n");
  return 1; }
else {
  this_player()->move_player("down#players/eurale/Keep/k17.c");
  return 1; }
}
