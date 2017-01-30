inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;

 if(arg) return;
 short_desc="The Fallen Lands";
 long_desc=
"You are in a dug out passage beneath the shack.  It is completely dark\n"+
"at this point, however to the north there is a well lit room.  On the\n"+
"south wall is a ladder which leads back up into the shack.\n";
 set_light(0);
 items=({
	 "ladder",
"The ladder is attached to the south wall of the passageway.  It is made\n"+
"from numerous sturdy branches which have been tied together",
	 "shack",
"The shack is directly above you.  Part of the roof can be seen from here",
     "room",
"The passage leads northward, into a room with flickering light",
     "passage",
"The passage has been dug out of the ground.  There are several supporting\n"+
"beams of wood on each side.  Roots are visible in the walls of the passage",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/hermit2.c", "up",
	 "/players/zeus/realm/taus/hermit5.c", "north",
 });
}

void init(){
	::init();
	add_action("n_dir", "north");
	add_action("up_dir", "up");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT";    }

status up_dir(){
	write("You ascend the ladder...\n");
	say(TP->QN+" ascends the ladder...\n");
	TP->MP("up#/players/zeus/realm/taus/hermit2.c");
	return 1;
}