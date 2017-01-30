#include "/players/pavlik/closed/colors.h"
#define MASTER "/players/pavlik/cloudcity/room/start.c"
#define ENV environment(this_object())
#define BASE 15

int broken;
int build_count;
int build_max;

reset(arg){
  if(arg) return;
  broken = 0;
  build_count = 0;
  build_max = BASE + random(BASE);
}

id(str) {
  if(build_count >= build_max)
	return str == "orc_machine" || str == "grapple" || str == "grapple-machine" ||
	str == "machine";
  else
	return str == "orc_machine" || str == "box" || str == "parts" ||
	str == "box of parts";
}

short() {
  if(broken) { return "A Grapple-Machine "+YEL+"[broken]"+NORM; }
  if(build_count >= build_max) { return "A Grapple-Machine "+GRN+"[running]"+NORM; }
  return "A box of parts";
}

long(){
  if(broken) {
	write("The bizzare Grapple-Machine has been smashed thoroughly.\n");
	write("Broken machine parts lay scattered around its base.\n");
  }
  else if(build_count >= build_max) {
	write("The Grapple-Machine is a heavy-duty winch and a strange engine.\n");
	write("The engine bangs away noisily as the winch slowly draws in a huge\n");
	write("thick cable.  If this machine isn't stopped somehow it may\n");
	write("pull the Cloud City right out of the sky!\n");
  }
  else {
	write("A box of strange parts.  These bits and pieces look like they may\n");
	write("might be put together to build something.\n");
  }
  return;
}

add_build_count(i) {
  if(!i) build_count++;
  else build_count += i;
  if(build_count >= build_max) { build(); }
}
set_build_count(i) { build_count = i; }
query_build_count() { return build_count; }
query_build_max() { return build_max; }

set_broken(i) { broken = i; }
query_broken() { return broken; }

get() {
  return 1;
}

drop() {
  return 1;
}

clean_up() {
  return 1;
}

query_weight() {
  return 9999;
}

init() {
  add_action("smash_machine", "smash");
}

machine_init() {
  if(!present("engineer", ENV)) {
	move_object(clone_object("players/pavlik/cloudcity/mon/orc_engineer"), ENV);
  }
  return 1;
}

smash_machine(str) {
  if(build_count >= build_max && id(str)) {
	if(broken) {
		write("The machine is already broken.\n");
		return 1;
	}
	if(present("orc", ENV)) {
		write("The orc will not let you get close enough.\n");
		return 1;
	}
	write("You SMASH the grapple-machine!\n");
	tell_room(ENV, "\n"+
		capitalize(this_player()->query_name())+" "+HIR+"smashes"+NORM+" the grapple-machine!\n"+
		"The machinery comes to a grinding halt!  Gears grind angrily and metal\n"+
		"screeches loudly as the evil machine "+HIR+"EXPLODES!\n\n"+NORM);

	MASTER->realm_tell("\n"+
	HIW+"You hear an explosion in the distance!\n"+
	"One of the Orc's evil grappling-machines has been destroyed!\n\n"+NORM, ENV);

	MASTER->add_grapple_count(-1);
	broken = 1;
	return 1;
  }
}

build() {
  tell_room(ENV, "\n"+
	"The Orc Engineer stands up and starts to cackle madly.\n"+
	"Orc Engineer exclaims: It's done!  It's done!  I have done it!\n"+
	"The mysterious contraption suddenly "+GRN+"roars to life!\n\n"+NORM);
  tell_room(ENV, "\n"+
	"The ground jerks suddenly beneath your feet as the giant winch\n"+
	"begins to turn and gather in the steel cable.\n\n");

  MASTER->add_grapple_count(1);
  call_out("build_chat", 9);
  return 1;
}

build_chat() {
  if(broken) return 1;
  if(build_count < build_max) return 1;
  switch (random(5)) {
	case 0: tell_room(ENV, "The grapple-machine thumps noisily.\n"); break;
	case 1: tell_room(ENV, "The Cloud City shifts under your feet.\n"); break;
	case 2: tell_room(ENV, "The giant winch continues to pull in cable.\n"); break;
	case 3: tell_room(ENV, "Black smoke pours out of the grapple-machine as it works.\n"); break;
  }
  call_out("build_chat", 5+random(10));
  return 1;
}

