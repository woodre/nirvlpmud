inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f12.c            *
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
  if( !present("anteaus", this_object()) )
    call_out("get_anteaus", 1);
if(arg) return;
  set_light(1);
  short_desc = "forest";
  long_desc =
"    ~An Eastern Trail~\n\
  Progress along this narrow, overgrown path is next to impossible,\n\
and you find yourself having to stop several times for a rest. There\n\
doesn't seem to be any way forward. A rope ladder is ascending to a\n\
platform in a nearby tree. Giant, ancient trees tower over everything\n\
on all sides.\n";

  items =
  ({
    "rope",
    "It is tied to some wood boards, probably made for climbing",
    "ladder",
    "It's made of rope and wood boards. You could try to climb it",
    "platform",
    "A flat wood surface with some primitive walls around it",
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
    "/players/angel/area/nox/room/f11.c",    "west",
  });
}
void get_anteaus(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/angel/area/nox/npc/anteaus.c"), this_object());
    }
  tell_room(this_object(), "\n");
}

init() {
  ::init();
  add_action("climb", "climb");
}

status climb(string arg) {
  if (!arg) {
    notify_fail("Climb what?\n");
    return 0;
  }

  if (arg == "tree") {
    notify_fail("Climb which tree?\n");
    return 0;
  }

  if (arg == "ladder" || arg == "ancient") {
    this_player()->move_player("You climbed the ladder up the ancient tree#/players/angel/area/nox/room/hut.c");
    return 1;
  }

  notify_fail("Climb what?\n");
  return 0;
}
