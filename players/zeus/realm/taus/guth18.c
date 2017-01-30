inherit "room/room";
#include "/players/zeus/closed/all.h"    /* guth18 */
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
"The forest is somewhat dense here.  To the west it is much more open,\n"+
"the sun is lighting up the forest floor.  To the east the forest is\n"+
"thicker and darker.  The path leads into the forest to the east.  The\n"+
"branches of the trees cross over the path, blocking out large patches\n"+
"of the blue sky.\n";
  set_light(1);
  items=({
	"path",
"The path seems to begin here, leading east into the forest.  To the\n"+
"west the forest is much more open, and the path becomes less obvious",
	"forest",
"The forest consists primarily of tall evergreen and maple trees.  To\n"+
"the east the forest gets much thicker and darker than it is here or\n"+
"to the west",
	"trees",
"The trees are all very tall, their branches crossing over the path\n"+
"blocking out much of the sky above you and to the east",
	"branches",
"The branches criss-cross together, making the forest dark",
    "sky",
"Patches of the blue sky can be seen overhead.  Much more blue sky is\n"+
"visible to the west",
    "sun",
"The sun is shining to the west",
    "leaves",
"A few brown leaves are scatted at your feet",
    "floor",
"The forest floor is lit up by the sun to the west.  It is more of a\n"+
"path where you are now",
  });
  dest_dir=({
"/players/zeus/realm/taus/guth17.c", "east",
"/players/zeus/realm/taus/guth10.c", "west",
 });
}

init(){
  ::init();
  add_action("e_dir", "east");
  add_action("w_dir", "west");
}

exit(){    if(this_player()) this_player()->clear_fight_area();   }
okay_follow() { return 1; }
realm(){   if(teleport) return "NT";    }
