inherit "/room/room";
#include "/players/pain/color.h"

reset() {
  short_desc = "The "+BOLD+GREEN+"Flet"+END;
  long_desc = "You are standing high above the Elven Vale on a walkway\n"+
	"through the "+BOLD+GREEN+"Flet"+END+". The walkway extends north and\n"+
	"southwest connecting one section of the flet to the next. Further\n"+
	"north you can see another platform amongst the trees. Over to the\n"+
	"east is a small fruitstand.\n";

  set_light(1);
  dest_dir = ({
	"/players/pain/NEW/flet/plat1", "east",
	"/players/pain/NEW/flet/flet5", "north",
	"/players/pain/NEW/flet/flet3", "southwest",
	});

  items = ({
	"fruitstand", "You gaze further east and see what appears to be a\n"+
		"fruitstand or grocery of some sort",
	"walkway", "You are standing on a wooden walkway supported by ropes\n"+
		"strung from tree to tree",

	});
	
  call_out("noises",10);
}

init() {
  ::init();
}

noises() {
int number;

   while(remove_call_out("noises") != -1);
   if ( !present(PLAYERID, this_object()) ) return;
  number = random(3);
  if(number == 0) {
	/* noise 1 */
	tell_room(this_object(),
		"You hear quiet bartering going on to the near east.\n");
  }
  if(number == 1) {
	/* noise 2 */
	tell_room(this_object(),
		"You hear the gentle creaking of the support ropes.\n");
  }
  if(number == 2) {
	/* noise 3 */
	tell_room(this_object(),
		"The smell of the fresh fruit fills your nose.\n");
  }
  call_out("noises",30);
  return 1;
}

realm() { return "NT"; }
