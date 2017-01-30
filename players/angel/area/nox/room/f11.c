inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f11.c            *
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
"    ~The Eastern Trail~\n\
  Progress along this narrow, overgrown path is next to impossible,\n\
and you find yourself having to stop several times for a rest. There\n\
doesn't seem to be any quick end to it either. There is a side trail\n\
which runs to the east.  Giant, ancient trees tower over everything\n\
on all sides.\n";

  items =
  ({
    "trail",
    "A long path",
    "tree",
    "A giant red wood tree that looks to be over 100 years old",
    "trees",
    "Giant red wood trees that look to be over 100 years old",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f04.c",    "south",
    "/players/angel/area/nox/room/f12.c",    "east",
  });
}
void get_fenri(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/angel/area/nox/npc/fenri.c"), this_object());
    }
  tell_room(this_object(), "A Fenri flys in.\n");
}
