inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f01.c            *
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
  if( !present("ohper", this_object()) )
    call_out("get_ohper", 1);
if(arg) return;
  set_light(1);
  short_desc = "forest";
  long_desc =
"    ~A Stream~\n\
  This stream is too wide and deep to wade across. A boat would be\n\
needed to cross. The water appears to be relatively clear and looks\n\
at least five feet deep. Giant, ancient trees tower over everything\n\
on all sides.\n";

  items =
  ({
    "stream",
    "Clear deep water, flowing fast",
    "water",
    "Clear deep water, flowing fast",
    "trees",
    "Giant red wood trees that look to be over 100 years old",
    "tree",
    "A giant red wood tree that looks to be over 100 years old",
    "boat",
    "There is no boat here",
  });
  dest_dir =
  ({
    "/players/angel/area/nox/room/f04.c",    "north",
    "/players/angel/area/nox/room/f02.c",    "west",
  });
}
void get_ohper(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/angel/area/nox/npc/ohper.c"), this_object());
    }
  tell_room(this_object(), "\n");
}
