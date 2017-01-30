inherit "room/room";	/*  guth13.c  */
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
"This is a thick part of the forest, however the path you are walking upon\n"+
"is very clearly defined and in no way obstructed by the trees.  The forest\n"+
"on either side of the path is very dark.  The path, which is covered in\n"+
"brown leaves, leads to the east and west from here.\n";
 set_light(1);
 items=({
  "forest",
"The forest is quite dense and very dark to the north and south of the\n"+
"path.  Travel off of the path would be impossible",
  "trees",
"The towering evergreen trees climb high into the sky.  There also appear\n"+
"to be many maple trees in this part of the forest",
  "sun",
"Though hard to see, the sun is visible up in the sky",
  "path",
"The path that leads through the forest is very clearly defined.  It is\n"+
"covered by a layer of brown leaves that look very beautiful",
  "leaves",
"Many brown leaves of various shades and shapes are spread across the path",
 });
 dest_dir=({
   "/players/zeus/realm/taus/guth14.c", "east",
   "/players/zeus/realm/taus/guth12.c", "west",
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
