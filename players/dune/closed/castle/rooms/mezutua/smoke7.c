inherit "room/room";
#include "definitions.h"


void init()
{
  int rnd;
  rnd = random(100);
  if (rnd <= 12)
  {
    target->command("cough");
  }
  else if (rnd <= 24)
  {
    write("Your eyes burn from the smoke.\n");
  }
  ::init();
}


reset(arg)
{
  if(!arg)
  {
    set_light(0);
    short_desc=("Smoke");
    long_desc=
"     A thick fog of hot smoke obscures your vision entirely. It would\n"+
"be easy to lose your sense of direction in here. The smoke is so thick,\n"+
"you can't help but gag. You can even feel the smoke sink into your \n"+
"clothes.\n";

   dest_dir=({
        CASTLEROOM+"/smoke4.c","south"  ,
        CASTLEROOM+"/smoke6.c","west"  ,
            });

   items=({
        "smoke","     The grey smoke obscures further vision",
   });
   }
}
