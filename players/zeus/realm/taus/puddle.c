inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){

	if(!present("renegade hunter"))
		MO(CO("/players/zeus/realm/NPC/hunter.c"), TO);

  if(arg) return;
 long_desc=
"You are in a very strange place.  It is rather hard to move, there is\n"+
"quite a bit of resistance to your every motion.  It is very hard to see,\n"+
"everything is a dark brown shade, and seems to go on for some distance.\n"+
"If you moved in an outward direction you could leave this bizarre place.\n";
/*
"You are in a very strange place.  It is hard to move, there is quite\n"+
"a bit of resistance to your every motion.  It is very hard to see,\n"+
"everything is a dark brown shade, and seems to go on for some distance.\n"+
"You think if you moved in an outward direction then you could leave this\n"+
"bizarre place.\n"; */
 set_light(0);
}

short(){ return "The Fallen Lands?"; }

void init(){
	::init();
	add_action("out_cmd", "out");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   return "NT";    }
okay_follow(){ return 1; }

status out_cmd(){
	write("You move in an outward direction...\n\n");
	TP->MP("out#/players/zeus/realm/taus/hermit3.c");
	return 1;
}

