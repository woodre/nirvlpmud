inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f09.c            *
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
  if(! present("nafrayu", this_object()) )
    call_out("get_nafrayu", 1);
if(arg) return;
  set_light(1);
  short_desc = "forest";
  long_desc =
"    ~A Northern Path~\n\
  The path here is fairly clear and free of vegetation. It actually\n\
looks fairly well-maintained. Anyone listening can hear a distant\n\
singing to the north. Another path runs to the east of here. Giant,\n\
ancient trees tower over everything on all sides.\n";

  items =
  ({
    "vegetation",
    "There is none",
    "tree",
    "A giant red wood tree that looks to be over 100 years old",
    "trees",
    "Giant red wood trees that look to be over 100 years old",
    "path",
    "A well worn trail",
    "paths",
    "Well worn trails",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f08.c",    "south",
    "/players/angel/area/nox/room/f10.c",    "east",
  });
}
void get_nafrayu(){
  for(x=0; x<1; x++)
  {
    move_object(clone_object("/players/angel/area/nox/npc/nafrayu.c"), this_object());
  }
  tell_room(this_object(), "\n");
}
