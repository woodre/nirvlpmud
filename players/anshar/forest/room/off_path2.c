#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="Wilderness trail";
  long_desc="     The trees ahead seem to call you, a relief, just out of\n"+
            "reach, from the bright ball of fire overhead. The sun holds no\n"+
            "mercy for you, and tints everything with shades of death.\n";
  items=({
    "trail", "The trail looks to have once been a deer track",
    "sun",  "Large and angry red, the sun beats down upon you fiercely",
    "trees", "You notice what appears to be blessed shade among the trees",
  });
  dest_dir=({
    FROOM+"off_path3", "east",
    FROOM+"off_path1", "west",
  });

}

realm() {return "NT"; }

