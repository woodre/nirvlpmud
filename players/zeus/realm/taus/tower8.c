inherit "room/room";	/*  tower8.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

reset(arg){
	if(arg) return;

 short_desc="Auseth's Tower";
 long_desc=
"You are standing in a dark little room.  The walls are all solid, made\n"+
"from grey stone blocks.  Numerous cobwebs are in the corners of the\n"+
"room.  It looks as though nobody has used this hiding place in years.\n"+
"The only way out is to 'leave' the way you came.\n";
 set_light(-2);
 items=({
	"walls",
"The walls are all solid, made from the grey stone that the rest of\n"+
"the tower is made from",
	"cobwebs",
"A few whispy cobwebs are up in the corners of the room",
	"blocks",
"Huge blocks of stone make up the walls of the room",
 });
 dest_dir=({ });
}


exit(){    if(TP) TP->clear_fight_area();     }
realm(){    return "NT";    }
okay_follow(){ return 1; }

void init(){
	::init();
	add_action("leave_cmd", "leave");
}

status leave_cmd(string str){
	TP->MP("out#/players/zeus/realm/taus/tower5.c");
	("/players/zeus/realm/taus/tower5.c")->set_one(0);
	return 1;
}