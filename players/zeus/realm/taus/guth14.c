inherit "room/room";	/*  guth14.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, guth, clone;

reset(arg){

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;

	if(!present("gurther")){   clone = random(9);   switch(clone){
    case 0..6: break;
	case 7:  MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
	case 8: for(guth = 0; guth < 2; guth++)
			MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
	return 1; }}
  if(arg) return;

 short_desc="The Fallen Lands";
 long_desc=
"You are on a very clear path that leads through the forest to the east\n"+
"and west.  To the north and south the forest is very dark and quite\n"+
"dense, making deviation from the path impossible.  The path itself is\n"+
"fairly wide, and covered by a layer of brown leaves.\n";
 set_light(1);
 items=({
  "forest",
"The forest is very dark and dense north and south of the path.  The\n"+
"ways to go are to the east and west",
  "trees",
"The towering evergreen and maple trees climb high into the sky.  They\n"+
"make the forest very dark and dense",
  "sun",
"Though hard to see due to the trees, the sun is visible up in the sky",
  "path",
"The path you walk upon is rather wide and covered in brown leaves.  It\n"+
"leads to the east and west in almost a straight line",
  "leaves",
"Many brown leaves of various shapes and shades of brown are spread\n"+
"across the path.  Many of them are in perfect condition",
 });
 dest_dir=({
   "/players/zeus/realm/taus/guth15.c", "east",
   "/players/zeus/realm/taus/guth13.c", "west",
 });
}

void init(){
	::init();
	add_action("e_dir", "east");
	add_action("w_dir", "west");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow() { return 1; }
