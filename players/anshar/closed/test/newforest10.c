
#include "/players/anshar/closed/ansi.h"
#include "/players/anshar/closed/mydef.h"
inherit "room/room";
int M;
reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc=(HIG+"Evergloom Forest"+NORM);
  long_desc="     The dark trees of the forest loom over you, shutting out\n"+
            "the light from above. All about you the sounds of the wild can\n"+
            "be heard now louder now softer. From the depths of the forest,\n"+
            "you can sense a great and ancient evil. \n";
  items=({
    "forest",  "The forest proper surrounds you, dark and haunting",
    "trees", "The trees appear twisted and dark",
  });
  dest_dir=({
    NROOM+"newforest9", "north",
  });
if(!present("delit"))
{
M = (random(10));
if (M < 3) move_object(clone_object(NMON+"delit"),this_object());
if (M < 5) move_object(clone_object(NMON+"delit"),this_object());
if (M < 8) move_object(clone_object(NMON+"delit"),this_object());

}
}

realm() {return "NT"; }
