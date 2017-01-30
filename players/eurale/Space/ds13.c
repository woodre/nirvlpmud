#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Deep Space";
long_desc =
  "  You stand at the base of one of the small mountains.  Up the side \n"+
  "you see a small hole that you might be able to get into if you can\n"+
  "manage to climb up.\n";

items = ({
	"hole","Looks like a small cave entrance",
});

dest_dir = ({
	"players/eurale/Space/ds14.c","climb",
	"players/eurale/Space/ds2.c","west",
});

}

init() {
  ::init();
  add_action("climb","climb");
}

climb() {
if(this_player()->query_attrib("luc") > random(40)) {
  write("You try to climb this red mountain but the stones keep breaking\n"+
	"away and you tumble back to the bottom....\n");
  this_player()->heal_self(-random(40));
  return 1; }
else {
  this_player()->move_player("up the mountain#players/eurale/Space/ds14.c");
  return 1; }
}
