#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(1);
  short_desc=(HIG+"The Chamber of Mist"+NORM);
  long_desc =
    "     Swirling mist fills the room. There are portals to several places.\n";
  items =
  ({
    "mist",  "The mist calls to you",
    "portal",  "A portal to another place",
    "portals",  "Portals to another place",
  }); 
  dest_dir =
  ({
    HROOM+"hall1", "hall",
    FROOM+"path1", "forest",
    "/room/orc_vall", "back",
  }); 
}

realm() {return "NT"; }
