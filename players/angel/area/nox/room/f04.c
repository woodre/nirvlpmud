inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f04.c            *
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
"    ~Another Junction~\n\
  The path once again divides, this time into northern and southern\n\
branches. To the northeast an impressive-looking hut looms over the\n\
treetops, while to the south the trail becomes significantly narrower\n\
and overgrown. A stream is slightly visible to the south.\n";

  items =
  ({
    "treetops",
    "Branches and leaves at the top of the trees",
    "stream",
    "Flowing water can slightly be seen",
    "path",
    "A well worn trail",
    "paths",
    "Well worn trails",
    "hut",
    "A lagre home built in a tree",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f11.c",    "north",
    "/players/angel/area/nox/room/f01.c",    "south",
    "/players/angel/area/nox/room/f05.c",    "west",
  });
}
void get_fenri(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/angel/area/nox/npc/fenri.c"), this_object());
    }
  tell_room(this_object(), "A Fenri flys in.\n");
}
