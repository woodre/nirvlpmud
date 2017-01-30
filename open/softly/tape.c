#include "/players/softly/closed/ansi.h";
inherit "/obj/treasure.c";
#define tpn this_player()->query_name()
reset (arg) {
	set_id("tape");
      set_short("A roll of "+BOLD+BLK+"duct tape"+NORM);
      set_long("A roll of handy duct tape, just 'tape name'!\n");
	set_weight(0);
}

init(){
  ::init();
    add_action("tapem","tape");
}

tapem(str){
  object target;
  if(!str){ write("Tape who?\n"); return 1; }
    target = find_living(str);
    write(tpn+ " pulls out some duct tape and tapes "+str+"'s mouth shut!\n");
    tell_object(target,
	 tpn+" tapes your mouth shut! That bastard!\n\n");
   move_object(clone_object("/open/softly/tapem"), target);
   return 1; }
 


