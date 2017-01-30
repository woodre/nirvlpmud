/*
File: rat2.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  Secret entrance to the rat's nest.
*/

#include "defs.h"

inherit ROOM;

reset(arg) 
{
  if (arg) return;
  set_light(1);
  short_desc="A rooftop";
  long_desc=
"  From the roof of this building you can see Calador's citscape,\n"+
"including the Builder's Cathedral, and the coliseum to the north-\n"+
"east.  There is a large building to the north that is quite close\n"+
"and of a similar height to this one.\n";
  items=({
    "roof","The roof isn't very firm and feels like it could collapse\n"+
           "at any moment beneath your weight",
    "cityscape","Hundreds of buildings from two to four stories fill this\n"+
                "bustling city",
    "cathedral","You can make out the cathedral's high steeple from this distance",
    "coliseum","The coliseum's high walls can be seen in the distance",
    "building","You find a plank that you can use to cross over to the other\n"+
               "building, which is in similar condition to this one"
  });
  dest_dir=({
    PATH+"rat1","down"
  });
}   

init() {
  ::init();
  add_action("cmd_jump","jump");
  add_action("cmd_cross","cross");
  add_action("smell","smell");
}
smell() {
  write("The air up here is relatively fresh.\n");
  return 1;
}

cmd_cross(str) {
  if(str && str=="plank") {
    write("You cross the plank and climb onto another roof.\n");
    say(this_player()->query_name()+" crosses a plank to another roof.\n");
    move_object(this_player(),PATH+"rat3");
    command("look",this_player());
    return 1;
  }
  notify_fail("Cross what?\n");
}
cmd_jump(str) {
  write("It is too far to jump.\n");
  return 1;
}
