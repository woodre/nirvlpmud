#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(1);
  short_desc=("A barn");
  long_desc="A barn.\n";
  items =
  ({
    "barn",  "A barn",
  });
  dest_dir =
  ({
    BROOM+"barn12", "north",
    BROOM+"barn10", "south",
    BROOM+"barn8", "east",
    BROOM+"barn14", "west",
  });
}

realm() {return "NT"; }
