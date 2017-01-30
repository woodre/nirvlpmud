#include "def.h"

inherit MYROOM;

reset(arg) {
  if(!present("inspector"))
    move_object(clone_object(PATH+"Npc/bumstead"),this_object());
  if (arg) return;
  set_light(1);
  short_desc="Bumstead's Office";
  long_desc=
"     Detective Bumstead's office is immaculately clean and neat.  His\n\
desk sits in the middle of the room facing the door.  A couple of\n\
filing cabinets and a few chairs round out his furniture.\n";
  items=({
    "desk","A folder full of crime scene photos is on his desk",
    "cabinets","The filing cabinets are all neatly locked",
    "chairs","A few simple wooden chairs possibly stolen from a\n"+
             "nearby catholic school"
  });
  dest_dir=({
    PATH+"squadrm","north"
  });
}   
