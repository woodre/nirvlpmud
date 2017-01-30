#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="Wilderness trail";
  long_desc="     You have moved off of the path and appear to be on a worn\n"+
            "trail leading into the dark wilderness. The trees ahead might\n"+
            "provide some relief from the sun overhead. West leads back to\n"+
            "the dusty path.\n";
  items=({
    "trail", "The trail looks to have once been a deer track",
    "sun",  "Large and angry red, the sun beats down upon you fiercely",
    "trees", "Perhaps you will be able to get a better look when you get closer",
    "path", "The path you left behind is barely visible through the break",
  });
  dest_dir=({
    FROOM+"off_path2", "east",
    FROOM+"path3", "west",
  });

}

realm() {return "NT"; }
