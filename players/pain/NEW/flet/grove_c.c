inherit "/room/room";
#include "/players/pain/color.h"

object climber;
object guard, guard2;

reset() {
  short_desc = "A "+BOLD+GREEN+"Grove"+END;
  long_desc = "You stand in the midst of a quiet, ancient "+BOLD+GREEN+"grove"+END+" in the\n"+
	"middle of the "+BOLD+GREEN+"Elven Vale"+END+". Mystery shrouds this place and\n"+
	"you can't help but wonder if you'll find the entrance to the "+BOLD+GREEN+"Elven Flet"+END+" here.\n"+
	"The trees are thick about you, and there is no real path other than that\n"+
	"which leads back to the vale. It is cool and damp here, the sunlight is blocked\n"+
	"from up above by the thick canopy of trees.\n"+
	"You sense a definate energy here.\n\n"+
	"A large "+BOLD+GREEN+"Mallorn Tree"+END+" stands out from the others here.\n";

  set_light(1);
	
  dest_dir = ({
	"/players/pain/NEW/flet/grove3", "north",
	"/players/pain/NEW/flet/grove2", "northeast",
	"/players/pain/NEW/flet/grove1", "east",
	"/players/pain/NEW/flet/grove8", "southeast",
	"/players/pain/NEW/flet/grove7", "south",
	"/players/pain/NEW/flet/grove6", "southwest",
	"/players/pain/NEW/flet/grove5", "west",
	"/players/pain/NEW/flet/grove4", "northwest",
	});

  items = ({
	"tree", "A rather imposing "+BOLD+GREEN+"Mallorn"+END+" stands in the center of this small"+
		"clearing.\nAs you gaze closer at it, it becomes apparent that this is the largest tree"+
		"that you have\never seen. Perhaps you could <climb> this tree",
	"mallorn", "A rather imposing "+BOLD+GREEN+"Mallorn"+END+" stands in the center of this small"+
		"clearing.\nAs you gaze closer at it, it becomes apparent that this is the largest tree"+
		"that you have\never seen. Perhaps you could <climb> this tree",
	});

  if(!present("guard")) {
	guard = clone_object("/players/pain/NEW/flet/Mon/elf_g");
	guard2 = clone_object("/players/pain/NEW/flet/Mon/elf_g");
	if(call_other("/players/pain/NEW/flet/f2path3","query_murder")) {
		guard->set_aggressive(1);
		guard2->set_aggressive(1);
	}
	move_object(guard,this_object());
	move_object(guard2,this_object());
  }	
  call_out("noises",10);
}

init() {
  ::init();
	add_action("climb", "climb");
}

climb(str) {
int ste;
int chance, message;

if(!str && str != "tree" && str != "mallorn") {
	write("What do you wish to climb?\n");
	return 1;
}
climber = this_player();
if(present("guard")) {
	write("The guard blocks you from the tree.\n\n");
	tell_room(this_object(),"Guard says: None may pass!\n");
	present("guard")->attack(this_player());
	return 1;
}

ste = climber->query_attrib("ste");
chance = random(35);
message = random(3);
if(ste < chance) {
	if(message == 0) {
		write("You attempt to climb the tree, but only manage about four feet before falling.\n");
		write("You hit the ground with a T H U N K\n");
		climber->hit_player(random(4));
		return 1;
	}
	if(message == 1) {
		write("You attempt to climb the tree, but only get about twelve feet off the ground before\n"+
			"losing your grip and falling.\n");
		write("You S L A M against the hard earth.\n");
		climber->hit_player(4+random(8));
		return 1;
	}
	if(message == 2) {
		write("You attempt to climb the tree and get about halfway up before falling back down to the earth.\n");
		write("The fall S M A S H E S you.\n");
		climber->hit_player(8+random(20));
		return 1;
	}
}
write("You begin climbing the tree and soon reach a point about 30 feet up.\n");
climber->move_player("up the tree#/players/pain/NEW/flet/flet1");
return 1;
}

noises() {
int number;

   while(remove_call_out("noises") != -1);
   if ( !present(PLAYERID, this_object()) ) return;
  number = random(3);
  if(call_other("/players/pain/NEW/flet/f2path3","query_murder")) {
	 if(number == 0) {
		/* noise 1 */
		tell_room(this_object(),
			"You can sense that something is wrong here.\nThe whole grove is mourning.\n");
	}
	if(number == 1) {
		/* noise 2 */
		tell_room(this_object(),
			"You feel a strong angry energy surrounding you.\n");
	}
	if(number == 2) {
		/* noise 3 */
		tell_room(this_object(),
			"The whole grove seems to echo, "+BOLD+RED+"M U R D E R"+END+".\n");
	}
  }
   if(number == 0) {
	/* noise 1 */
	tell_room(this_object(),
 		"You think you hear noise eminating from the trees above you.\n");
  }
  if(number == 1) {
	/* noise 2 */
	tell_room(this_object(),
		"A mysterious energy surrounds you, beckoning you deeper into the grove.\n");
  }
  if(number == 2) {
	/* noise 3 */
	tell_room(this_object(),
		"You think you hear something creak high above you.\n");
  }
  call_out("noises",10);
  return 1;
}
