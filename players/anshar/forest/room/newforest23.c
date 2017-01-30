#include "/players/anshar/closed/mydef.h"
#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
inherit "room/room";
int M;

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc=(HIG+"Evergloom Forest"+NORM);
  long_desc="The dark trees of the forest loom over you, shutting out the\n"+
            "light from above. All about you the sounds of the wild can be\n"+
            "heard now louder now softer. From the depths of the forest, you\n"+
            "can sense a great and ancient evil. \n";
  items=({
    "forest",  "The forest proper surrounds you, dark and haunting",
    "trees", "The trees appear twisted and dark",
  });
  dest_dir=({
    FROOM+"newforest22", "south",
 });
if(!present("delit"))
{
M = (random(10));
if (M < 2) move_object(clone_object(FMON+"delit"),this_object());
if (M < 4) move_object(clone_object(FMON+"delit"),this_object());
if (M < 7) move_object(clone_object(FMON+"delit"),this_object());
}

}

realm() {return "NT"; }
