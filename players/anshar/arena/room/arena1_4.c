#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "/players/anshar/inherit/room";

reset(arg)
{
  if (arg) return 0;
  set_light(1);
  short_desc=("The Arena");
  long_desc="The arena floor is covered in dirt.\n";
  items =
  ({
    "barn",  "A barn",
  });
  dest_dir =
  ({
    AROOM+"arena1_2", "east",
  });
}

realm() {return "NT"; }
