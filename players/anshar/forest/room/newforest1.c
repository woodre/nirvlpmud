#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc=(HIG+"Evergloom Forest"+NORM);
  long_desc="The dark trees of the forest loom over you, shutting out the\n"+
            "light from above. All about you the sounds of the wild can be\n"+
            "heard now louder now softer. From the depths of the forest, you\n"+
            "can sense a great and ancient evil. Perhaps you should go back\n"+
            "now while you still are able.\n";
  items=({
    "forest",  "The forest proper surrounds you, dark and haunting",
    "trees", "The trees appear twisted and dark",
  });
  dest_dir=({
    FROOM+"newforest8", "east",
    FROOM+"newforest2", "south",
    FROOM+"off_path3", "back",
  });

}

realm() {return "NT"; }
