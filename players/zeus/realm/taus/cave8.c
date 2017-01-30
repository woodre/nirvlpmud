inherit "room/room";	/*  cave8.c  */
#include "/players/zeus/closed/all.h"
int demon;
object demn, demn2;

reset(arg){

  if(arg) return;
  if(!present("ooze"))
    MO(CO("/players/zeus/realm/NPC/ooze.c"), TO);


 short_desc="A cavern";
 long_desc=
"The narrow cavern widens a bit here into a small crevice.  The rock\n"+
"walls are cold and wet, slowly dripping with water.  This place doesn't\n"+
"look like natural light has touched it in years.  The only way back\n"+
"is out the way you came from the north.\n";
  set_light(0);
 items=({
   "water",
"Small drops of water collect on the walls and slowly fall to the ground",
	 "walls",
"The walls of the tunnel are very uneven and many jagged rocks protrude\n"+
"out from them",
 });
 dest_dir=({ "/players/zeus/realm/taus/cave6.c", "north", });
}

exit(){    if(TP) TP->clear_fight_area();     }
realm() {  return "NT"; }
okay_follow() { return 1; }
