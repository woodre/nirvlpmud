inherit "/room/room";
#include "/players/pain/color.h"

reset() {
  short_desc = "The "+BOLD+GREEN+"Flet"+END;
  long_desc = "You are standing high above the Elven Vale on a walkway\n"+
	"through the "+BOLD+GREEN+"Flet"+END+". The walkway extends north and\n"+
	"south connecting one section of the flet to the next. Further\n"+
	"north you can see another platform amongst the trees.\n"+
	"The sun shines brightly upon you, warming your face and shoulders.\n";

  set_light(1);
  dest_dir = ({
	"/players/pain/NEW/flet/flet6", "north",
	"/players/pain/NEW/flet/flet4", "south",
	});

  items = ({
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
		"The soft sounds of the wind through the flet fill your ears.\n");
  }
  if(number == 1) {
	/* noise 2 */
	tell_room(this_object(),
		"You hear the gentle creaking of the support ropes.\n");
  }
  if(number == 2) {
	/* noise 3 */
	tell_room(this_object(),
		"The sun shines brightly down upon you filling you with hope.\n");
  }
  call_out("noises",30);
  return 1;
}

realm() { return "NT"; }
