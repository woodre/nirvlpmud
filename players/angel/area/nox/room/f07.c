inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f07.c            *
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
"    ~A Western Path~\n\
  This path is certainly less overgrown than the north-south one.\n\
Anyone is able to move relatively quickly through the forest,\n\
stopping only occasionally to hack away an overhanging branch or\n\
vine. Giant, ancient trees tower over everything on all sides.\n";

  items =
  ({
	"trees",
    "Giant red wood trees that look to be over 100 years old",
	"tree",
    "A giant red wood tree that looks to be over 100 years old",
    "branch",
    "One limb in the tree",
    "limb",
    "One branch in the tree",
    "vine",
    "A long, rope-like plant clinging to the trees",
    "forest",
    "Many large trees and shrubs clumped together",
    "path",
    "A well worn trail",
    "paths",
    "Well worn trails",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f06.c",    "east",
    "/players/angel/area/nox/room/f08.c",    "west",
  });
}
void get_fenri(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/angel/area/nox/npc/fenri.c"), this_object());
    }
  tell_room(this_object(), "A Fenri flys in.\n");
}
