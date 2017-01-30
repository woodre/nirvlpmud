inherit "room/room";	/*  cave6.c  */
#include "/players/zeus/closed/all.h"
int demon;
object demn, demn2;

reset(arg){
	if(!present("demon")){   
		demn = CO("/players/zeus/realm/NPC/demon_large.c");
		demn2 = CO("/players/zeus/realm/NPC/demon_large.c");
		MO(demn, TO);
		MO(demn2, TO);
		demn2->set_aggressive(0);
		demn2->set_hp(700);
		demn->set_wc(50);
	}
 if(arg) return;

 short_desc="A cavern";
 long_desc=
"You stand within a large chamber deep within the bowels of the Fallen\n"+
"Lands.  Large rocks protrude from the walls, which are very wet.  A\n"+
"tunnel leads up from here towards the surface.  The large room seems\n"+
"to continue to the north.  There is also a narrow tunnel which leads\n"+
"deeper into the ground south.  The room is horribly cold.\n";
 set_light(0);
 items=({
	 "walls",
"The walls of the tunnel are very uneven and many jagged rocks protrude\n"+
"out from them",
	 "chamber",
"This is a rather large chamber deep within the Fallen Lands.  It is\n"+
"terribly cold and the air is rather stale",
	 "tunnel",
"The tunnel leads up, towards the surface",
	 "rocks",
"The jagged rocks protrude from the sides of the tunnel.  Many of them\n"+
"have moisture collecting on them",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/cave5.c", "climb",
   "/players/zeus/realm/taus/cave8.c", "south",
 });
}

void init(){
  ::init();
  add_action("north_cmd", "north");
  add_action("south_cmd", "south");
  add_action("climb_cmd", "climb");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm() {  return "NT"; }
okay_follow() { return 1; }

climb_cmd(){
	if(present("a huge cursed demon")){
		write("A demon blocks your way.\n");
		return 1;
	}
}

south_cmd(){
	if(present("a huge cursed demon"))
		write("A demon blocks your way.\n");
	else
		TP->MP("south#/players/zeus/realm/taus/cave8.c");
  return 1;
}

north_cmd(){ 
	if(present("a huge cursed demon"))
		write("A demon blocks your way.\n");
	else
		TP->MP("north#/players/zeus/realm/taus/cave7.c");
  return 1;
}
