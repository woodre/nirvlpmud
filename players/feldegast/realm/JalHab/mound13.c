#include "defs.h"

inherit MNDROOM;

int found;

void reset(int arg)
{
  int i;
  if(!present("corpse"))
    for(i=2+random(5); i > 0; i--)
    {
      object corpse;
      corpse=clone_object("/obj/corpse.c");
      switch(random(5))
      {
         case 0: corpse->set_name("p'kalian");break;
         case 1: corpse->set_name("human");break;
         case 2: corpse->set_name("cactipod");break;
         case 3: corpse->set_name("p'kalian");break;
         case 4: corpse->set_name("animal");break;
       }
       corpse->set_corpse_level(1+random(7));
       move_object(corpse,this_object());
    }
  if(!arg)
  {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  Before you lies a natural cavern that is perhaps twenty meters wide,\n\
its high ceiling dotted with short stalactites.  The floor, on the\n\
other hand, is a hellish nightmare of old bones and corpses piled high\n\
atop the rotting remains of their predecessors, ribcages picked clean\n\
of their flesh sitting next to a grinning skull that still has flesh\n\
remaining.\n";
    items=({
      "cavern", "The cavern is perhaps twenty meters wide",
      "ceiling", "It is dotted with short stalactites",
      "stalactites", "The short stalactites dot the ceiling",
      "floor", "The cave is so littered with carrion that it is difficult\n"+
               "to make out the floor",
      "bones", "It is difficult to tell how long these have been here",
      "corpses", "The corpses are so well preserved that it is difficult to tell\n"+
                 "how long they have been here",
      "remains", "The corpses appear to have been poorly treated, with limbs\n"+
                 "ripped off for easy transportation",
      "skull", "The skull seems odd.  Perhaps it bears further investigation",
    });
    dest_dir=({
      PATH+"mound12.c","east",
    });
 
  }
  if(!present("myrmidar"))
    for(i=1+random(3); i > 0; i--)
      move_object(clone_object(MON_PATH+((random(2))?"myrm-warrior":"myrm-worker")),this_object());
  if(!random(2)) move_object(clone_object(MON_PATH+"myrm-leader"),this_object());

}
void init()
{
  ::init();
  add_action("cmd_search","search");
}
int cmd_search(string str)
{
  if(!str)
  {
    notify_fail("Search what?\n");
    return 0;
  }
  if(present("myrmidar"))
  {
    write("The myrmidar block your path.\n");
    return 1;
  }
  if(str!="skull" || found)
  {
    write("You find nothing.\n");
    return 1;
  }
  found=1;
  write("You find an odd looking key beneath the skull, which you decide\nto take with you.\n");
  move_object(clone_object(OBJ_PATH+"key-earth"),this_player());
  this_player()->add_weight(4);
  return 1;
}
