/*
This is an example of a room with a random exit.  This is just one of
dozens of methods of doing random exits, so don't feel like you have
to do it this way.  The other rooms in this directory do random exits
differently, and you can mix and match different methods to suit
your needs.
- Feldegast
*/
#include "defs.h"

inherit "room/room";

object *dests;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The void";
  long_desc=
"  You float aimlessly through the void, a field of stars surrounding\n\
you.  You have no conception of up or down, or time and space.  The\n\
only thing you can do is wander.\n";
  items=({
  });  
}

init() {
  add_action("cmd_wander","wander");
}

cmd_wander(str) {
  string file;
  string *dests;
  string dest;
  file=read_file("/open/TELE_ERR");
  dests=explode(file,"\n");
  dest=dests[random(sizeof(dests))];
  say(TPN+" slips out of the void.\n");
  write("You sense yourself falling, tumbling through the void, and then\n"+
        "suddenly you land with a loud...\n\n\t\t\t\t...THUMP!\n\n");
  move_object(TP,dest);
  command("look",TP);
  say(TPN+" falls through the air and lands with a loud THUMP!\n");
  return 1;
}

