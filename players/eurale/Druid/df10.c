#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Ironwood Tree";
long_desc =
	"  You stand in the center of a large carved-out cavern.  The\n"+
	"walls of this beautiful Ironwood tree have been scraped smooth\n"+
	"and hand polished to give it a rich look.  There is a plaque\n"+
	"hanging on the wall above the door where you entered.  Doors\n"+
	"lead off in all directions to smaller rooms of some kind.\n";

items = ({
	"plaque","The "+BOLD+GRN+"Druid Guild"+NORM+
		" thanks you for your patronage and hopes\n"+
		"you'll come back to visit again soon",
	"walls","Sanded and waxed Ironwood... beautiful",
	"doors","Openings cut into this huge tree leading to other areas",
});

dest_dir = ({
	"players/eurale/Druid/inn.c","north",
	"players/eurale/Druid/df12.c","south",
	"players/eurale/Druid/df11.c","east",
	"players/eurale/Druid/pub.c","west",
	"players/eurale/Druid/df9.c","exit",
});

}

init() {
  ::init();
  add_action("south","south");
}

south() {
  if(this_player()->query_guild_name() != "druid") {
    write("An unseen force stops you and whispers..'Druids Only'\n");
    return 1; }
  else {
    this_player()->move_player("south#players/eurale/Druid/df12.c");
    return 1; }
}
