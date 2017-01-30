inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/nox/room/f10.c            *
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
  if( !present("lya", this_object()) )
    call_out("get_lya", 1);
if(arg) return;
  set_light(1);
  short_desc = "forest";
  long_desc =
"    ~An Impasse~\n\
 The path ends here in a small clearing with a small, shallow pool\n\
of crystal clear water. You feel strangely at ease here. Up ahead,\n\
anyone can see some sort of clearing but there is a cliff preventing\n\
movement to the north. A small opening of some kind can be seen to\n\
the southeast. Giant, ancient trees tower over everything on all\n\
sides.\n";

  items =
  ({
    "pool",
    "A small body of water",
    "water",
    "It is crystal clear",
    "cliff",
    "A steep side of a mountain",
    "opening",
    "It looks as if you may be able to crawl through it",
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
    "/players/angel/area/nox/room/f09.c",    "west",
  });
}
void get_lya(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/angel/area/nox/npc/lya.c"), this_object());
    }
  tell_room(this_object(), "\n");
}
  
init() {
  ::init();
  add_action("crawl", "crawl");
}

status crawl(string arg) {
  if (!arg) {
    notify_fail("Crawl where?\n");
    return 0;
  }

  if (arg == "tree") {
    notify_fail("Crawl where?\n");
    return 0;
  }

  if (arg == "brush" || arg == "opening") {
    this_player()->move_player("you crawl through the rough brush#/players/angel/area/nox/room/f06.c");
    return 1;
  }

  notify_fail("Crawl where?\n");
  return 0;
}
