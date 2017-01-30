/*
File: rat1.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  Secret entrance to the rat's nest.
*/

#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Derelict building";
  long_desc=
"  The interior framework of this building has rotted, leaving\n"+
"it a hollow shell.  Wreckage litters the floor of this two-story\n"+
"building.  Near the window you crawled through is a pile of dead\n"+
"rats.\n";
  items=({
    "shell","The wood interior of the building has rotted, leaving a\n"+
            "shell of brick and stone",
    "wreckage","The wreckage here is so thick that it is difficult to walk.\n"+
               "It is composed of wooden beams, tiles, and other brick-a-brack",
    "window","You have a good view of Copper street through the boarded up\n"+
             "window",
    "rats","The pile of dead rats is obviously the source of the intense smell","rats","The pile of dead rats is obviously the source of the intense smell",
    "pile","The pile of dead rats is obviously the source of the intense smell"
  });
  dest_dir=({
    PATH+"copper3","out"
  });
}   

init() {
  ::init();
  add_action("search","search");
  add_action("cmd_climb","climb");
  add_action("smell","smell");
}

search() {
  write("You search through the rubble and find an ad hoc ladder leading\n"+
        "up through a hole in the ceiling.\n");
  say(this_player()->query_name()+" searches through the rubble.\n");
  return 1;
}

smell() {
  write("The stench here is overwhelming.  You have to force yourself\n"+
        "to not run from the building gasping for air.\n");
  return 1;
}

cmd_climb(str) {
  if(str && str=="ladder") {
    write("You climb the ladder up to the roof.\n");
    say(this_player()->query_name()+" climbs up a hidden ladder.\n");
    move_object(this_player(), PATH+"rat2");
    command("look",this_player());
    return 1;
  }
  notify_fail("Climb what?\n");
}

