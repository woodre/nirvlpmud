inherit "room/room";	/*  cave5.c  */
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

 short_desc="A cavern";
 long_desc=
"The tunnel slants down at a very steap angle here.  It is hard to stay\n"+
"on your feet.  The sides of the tunnel are rather uneven, with many\n"+
"jagged rocks visible in them.  The tunnel continues down to the west\n"+
"and seems to expand into a larger room as it gets farther down.\n";
 set_light(0);
 items=({
	 "walls",
"The walls of the tunnel are very uneven and many jagged rocks protrude\n"+
"out from them",
	 "tunnel",
"The tunnel is slanting down at a steep angle to the west",
	 "rocks",
"The jagged rocks protrude from the sides of the tunnel.  Many of them\n"+
"have moisture collecting on them",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/cave2.c", "climb",
	 "/players/zeus/realm/taus/cave6.c", "down",
 });
}


exit(){    if(TP) TP->clear_fight_area();     }
realm() {  return "NT"; }
okay_follow() { return 1; }