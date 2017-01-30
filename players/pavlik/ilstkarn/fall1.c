#include <ansi.h>
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Down the Chasm";
  long_desc=
  "You begin the hazardous trek down the steep, narrow trail of the\n"+
  "chasm.  The loose dirt slides precariously under your feet and\n"+
  "you have to keep reminding yourself not to look down.\n";
  dest_dir=({
	"/players/pavlik/ilstkarn/null", "up",
	"/players/pavlik/ilstkarn/null", "down",
  });
}

query_ilstkarn(){ return "fall1"; }
realm(){ return "NT"; }
query_nofollow(){ return 1; }
query_no_teleport(){ return 1; }

init() {
  ::init();
  if(this_player()->is_player()) {
	call_out("fall_guy", 5+random(5), this_player());
  }
  add_action("down","down");
  add_action("up","up");
}

down() {
  write("Yes, yes.\n");
  return 1;
}

up() {
  write("It's a little late for that, don't ya think?\n");
  return 1;
}

fall_guy(ob) {
  if(ob && present(ob, this_object())) {
	tell_object(ob, "\n\n"+
	"     "+HIW+"You lose your footing and "+HIR+"fall"+HIW+" into the Chasm!   \n"+NORM+
	"\n\n");
	ob->move_player("down!!!#players/pavlik/ilstkarn/fall2");
	return 1;
  }
}

