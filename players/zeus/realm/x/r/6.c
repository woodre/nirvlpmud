inherit "room/room";   
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/dirs.h"
int x, tp;
reset(arg){
 if(!arg){
  set_light(0);
  dest_dir=({ });
} }

short(){ return "The Fallen Lands"; }

void init(){  
	::init();  
	x = random(ROOMS);  
	tp = random(TLP);
	add_action("look", "look");
	add_action("look", "l");
	add_action("move_dir", "north");
	add_action("move_dir", "northeast");
	add_action("east_dir", "east");
	add_action("move_dir", "southeast");
	add_action("move_dir", "south");
	add_action("move_dir", "southwest");
	add_action("move_dir", "west");
	add_action("move_dir", "northwest");
}
exit(){ if(this_player()) this_player()->clear_fight_area(); }
realm(){  if(tp) return "NT"; }
okay_follow() { return 1; }
#include "/players/zeus/realm/x/longs.h"

