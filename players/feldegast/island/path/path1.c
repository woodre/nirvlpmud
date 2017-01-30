#include "/players/feldegast/defines.h"

inherit ROOM;

string quester;


object hag;
reset(arg) {
  if (arg) return;
  if(!hag) {
    hag=clone_object("/players/feldegast/island/path/uggl");
    move_object(hag,this_object());
  }
  set_light(1);
  short_desc="A path through the jungle";
  long_desc=
"     This is a narrow path going through the heart of\n"+
"the jungle.  Vines and green foliage dangle across\n"+
"it, making travel slow and cumbersome.\n";
  items=({
    "vines","Vines or snakes.  You're just trying to think positively",
    "foliage","Bushes, tall grass, moss, and the roots of tall trees"
  });
  dest_dir=({
    "/players/feldegast/island/jungle/jungle19","west",
    "/players/feldegast/island/path/path2","east"
  });
}

init() {
  ::init();
  if(!quester && TP->is_player()) {
    quester=TP->query_real_name();
  }
  if(quester && TP->is_player() && TP->query_real_name()!=quester) {
    write("You notice footprints leading along the path and decide\n"+
          "not to disturb whoever made them.\n");
    TP->move_player("west#/players/feldegast/island/jungle/jungle19");
  }
}
realm() { return "NT"; }
