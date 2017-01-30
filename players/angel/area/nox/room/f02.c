inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f02.c            *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           07/01/08                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>


int x;
reset(arg)
{
  ::reset(arg);
  if( !present("fenri", this_object()) )
    call_out("get_fenri", 1);
if(arg) return;
  set_light(1);
  short_desc = "forest";
  long_desc =
"    ~A Path Through Noxwood~\n\
  This is a narrow path that runs deep into the forest of Noxwood.\n\
Giant, ancient trees tower over everything on all sides, and sweet\n\
songbirds sing in their lofty branches. However, despite this serene\n\
scene, you can't shake the feeling that you're being watched.\n";

  items =
  ({
	"trees",
    "Giant red wood trees that look to be over 100 years old",
	"tree",
    "A giant red wood tree that looks to be over 100 years old",
    "bird",
    "This bird has an extraordinary ability to mimic natural and artificial sounds.\n\
     It also has extraordinary plumes of neutral colored tail feathers",
    "songbird",
    "This bird has an extraordinary ability to mimic natural and artificial sounds.\n\
     It also has extraordinary plumes of neutral colored tail feathers",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f05.c",       "north",
    "/players/angel/area/nox/room/entrance.c",  "south",
    "/players/angel/area/nox/room/f01.c",       "east",
    "/players/angel/area/nox/room/f03.c",       "west",
  });
}
void get_fenri(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/angel/area/nox/npc/fenri.c"), this_object());
    }
  tell_room(this_object(), "A Fenri flys in.\n");
}
