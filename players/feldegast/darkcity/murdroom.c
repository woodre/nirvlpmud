#include "def.h"

inherit MYROOM;

reset(arg) {
  if(!present("murdoch"))
    move_object(clone_object(PATH+"Npc/murdoch"),this_object());
  if (arg) return;
  set_light(1);
  short_desc="A motel room";
  long_desc=
"    This is a seedy motel room that looks like it's been lived in for\n\
quite a while.  Next to the bathroom door to the east is a puddle of\n\
water and some broken glass.  Lying next to the bed are the remains of\n\
a half-naked woman.\n";
  items=({
    "door","A half-open wooden door",
    "puddle","There is glass in the puddle, perhaps from a fish bowl",
    "glass","It looks like it came from a fish bowl",
    "bed","The bed is messy",
    "remains","The woman's corpse has been mutilated with bloody spiral\n"+
             "cuts across her pale skin",
    "woman","The woman's corpse has been mutilated with bloody spiral\n"+
             "cuts across her pale skin"
  });
  dest_dir=({
    PATH+"bathroom","east",
    PATH+"hallway","south"
  });
}   
