inherit "room/room";
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The forest is open here, the trees and plants are not crowding the\n"+
"path.  The path continues to the east and to the south from here.\n"+
"To the west a structure can be seen entangeled in the forest.  Also\n"+
"to the southeast pillars are visible through the thick cloak of trees\n"+
"and plants.\n";
  items=({
"trees", "The trees all appear ancient, and act as guardians of the forest",
"undergrowth", "The undergrowth is not crowding the path here",
"pillars", "The pillars are worn, cracked, and faded.  It is a miracle that"+
   " they\neven stand at all, although the forest does help hold them up",
"structure", "The structure is hard to see because of the plants which"+
          " have consumed\nit.  It is broken to pieces like all the others",
"path", "The path is rather dry and leads off in two directions",
"plants", "There are some beautiful plants growing amongst the trees here",
  });
  dest_dir=({
"/players/zeus/realm/city/path13.c", "east",
"/players/zeus/realm/city/path7.c", "south",
  });
}  }

  init(){
  ::init();
  add_action("e_dir", "east");
  add_action("s_dir", "south");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }
