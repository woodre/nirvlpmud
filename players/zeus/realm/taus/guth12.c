inherit "room/room";
#include "/players/zeus/closed/all.h"    /* guth12 */
#include "/players/zeus/closed/fl_demon.h"

int teleport, clone;

reset(arg){

    teleport = 0;  if(random(TFL_TLP)) teleport = 1;

    if(!present("gurther")){   clone = random(5);   switch(clone){
    case 0..3: break;
    case 4:  MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
    return 1; }}

    if(arg) return;
 short_desc="The Fallen Lands";
 long_desc=
"The forest is very open here.  The trees are growing farther apart, and\n"+
"most of the undergrowth has been cleared away.  The path opens up and\n"+
"blends in with the open forest.  The ground is scattered with small rocks\n"+
"and leaves.  There is a giant stump to the east.  The sun can be seen\n"+
"through the canopy of branches above.\n";
 set_light(1);
 items=({
	 "forest",
"The forest is very open here.  The trees are actually somewhat sparse,\n"+
"and the undergrowth has been pushed way back, making everything very\n"+
"open and bright.  To the south the forest gets much darker",
	 "trees",
"The powerful evergreen trees reach high into the sky.  They are growing\n"+
"far apart here, so their branches rarely ever touch",
	 "branches",
"The branches of the trees are reaching out across the land.  There are\n"+
"too few trees for their branches to block out the sky",
	 "sky",
"The beautiful blue sky is visible all around.  Soft white clouds are\n"+
"visible floating in the sky.  The sun is shining brightly",
	 "sun",
"The dark yellow sun is shining brightly through the trees.  The forest\n"+
"seems as though it's glowing with energy here\n",
	 "path",
"The path widens and fades here, making it very hard to distinguish",
	 "undergrowth",
"The undergrowth is not growing around here very much, and it makes the\n"+
"forest feel very open.  It makes the forest seem very pleasant",
	 "ground",
"The ground is very lush and soft.  Lots of grass is growing around here,\n"+
"and there are some rocks and leaves here and there",
	 "leaves",
"There are brown and green leaves dotting the ground here and there",
	 "stump",
"The stump is huge, about eight feet wide and six tall.  It looks as though\n"+
"the top of it was broken off long ago.  It is sitting at the edge of the\n"+
"dense forest like a monumental beast",
	 "rocks",
"Small rocks are scattered here and there on the ground",
 });
 dest_dir=({
     "/players/zeus/realm/taus/guth9.c", "northeast",
     "/players/zeus/realm/taus/guth13.c", "east",
     "/players/zeus/realm/taus/road4.c", "south",
     "/players/zeus/realm/taus/guth11.c", "west",
 });
}


void init(){
  ::init();
    add_action("ne_dir", "northeast");
    add_action("e_dir", "east");
    add_action("s_dir", "south");
    add_action("w_dir", "west");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow() { return 1; }
realm(){   if(teleport) return "NT";    }
