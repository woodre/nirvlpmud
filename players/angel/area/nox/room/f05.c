inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f05.c            *
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
"    ~A Fork in the Path~\n\
  At this point the path branches, with paths running to the east\n\
and west. A wild animal suddenly howls angrily some distance away,\n\
and you involuntarily jump. Giant, ancient trees tower over\n\
everything on all sides.\n";

  items =
  ({
	"trees",
    "Giant red wood trees that look to be over 100 years old",
    "tree",
    "A giant red wood tree that looks to be over 100 years old",
    "animal",
    "Whatever may be lurking around, it can't be seen right now",
    "path",
    "A well worn trail",
    "paths",
    "Well worn trails",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f02.c",    "south",
    "/players/angel/area/nox/room/f04.c",    "east",
    "/players/angel/area/nox/room/f06.c",    "west",
  });
}
void get_fenri(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/angel/area/nox/npc/fenri.c"), this_object());
    }
  tell_room(this_object(), "A Fenri flys in.\n");
}
