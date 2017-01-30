#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "/obj/treasure";

int chewing;

short() { return "A Deathbane root"; }

long() { write("     A small dark root with grey-green striating and\n"+
	       "a foul smell. Folklore says that to chew this root is\n"+
	       "to ward off the powers of the foul necromancers. With\n"+
	       "the odor eminating from it though, it is not something\n"+
	       "that would be pleasant to stick in one's mouth.\n"); }

id(str) { return str == "root" || str == "deathbane"; }

init() {
        add_action("chew_root", "chew");
}

chew_root(str) {
  object bitch;
  object stopob;
  bitch = present("azelane",environment(this_player()));
  if(!str || str != "root") { notify_fail("Chew what?\n");
  return 1; }
  if(!bitch) { destruct(this_object()); return 1; }
  if(!present(this_object(),this_player())) {
    write("You must get the root before eating it...\n");
    return 1; }
  if(chewing) { write("You are already chewing the root...\n"); return 1; }
  stopob = clone_object("/players/anshar/hall/item/stopper.c");
  stopob->set_meatname(this_player()->query_real_name());
  move_object(stopob,bitch);
  bitch->set_chance(0);
  call_out("stop_chewing",50);
  chewing = 1;
  write("You begin chewing the foul tasting root.\n");
  return 1;
}
stop_chewing() {
  object myenv;
  myenv = environment(this_object());
  if(myenv->is_player()) tell_object(myenv,"You finish chewing the root.\n");
  destruct(this_object());
  return 1;
}
