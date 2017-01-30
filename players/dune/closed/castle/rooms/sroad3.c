inherit "room/room";
#include "definitions.h"


int a, mosqs;   /* Added mosqs variable to limit mosquito spawns
                   11-24-2007 -Rumplemintz  */

init()
{
  add_action("goplace","west");
  add_action("goplace","w");
  add_action("listen","listen");
  add_action("search","search");
  ::init();
}


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    mosqs = 0;  /* Rumplemintz */
    short_desc="Southmost swamp path";
    long_desc=
"     You have entered an area of the swamp filled with small twigs, dry mud,\n"+
"and gaping holes in the ground. You hear a high pitched buzzing sound\n"+
"near dark pools of water. The pools are very still, making an ideal\n"+
"breeding ground for insect larvae. Off in the near distance,\n"+
"you see thick worm-like creatures crawling out of the water.\n";

    dest_dir=({
CASTLEROOM+"/2sse1.c","east"  ,
CASTLEROOM+"/sroad2.c","north"  ,
    });

    items=({
"tracks","     The tracks are very faint, you will have to search",
"nests", "     The nests are large bundles of hay. They stand 5 feet tall, but\n"+
         "seem to descend into the water, so they could be much larger. Wonder\n"+
         "what's inside",
"pools", "     The pools are completely still",
"worms", "     The wormies crawl from the water and into what looks like\n"+
         "nests. Hmm, wonder what's in those nests",
"creatures","     You mean worms?",
"worm",     "     You mean worms?",
    });
  }
}


goplace()
{
   say(TPN+" wanders off into the swamp.\n");
   write("You follow a faint trail through the swamp.\n");
   move_object(TP, CASTLEROOM+"/tempent.c");
   return 1;
}


search(str)
{
  if (!str)
  {
    write("What do you search?\n");
    return 1;
  }
  if (str == "nests")
  {
    if(!mosqs){           /* Rumplemintz */
       mosqs = 1;         /* Rumplemintz */
    write("Your search yields an unwelcome surprise.\n");
    for (a=1;a<=12;a++)
    {
      move_object(clone_object(CASTLEMONSTER+"/mosquitos.c"), this_object());
      write("A huge mosquito buzzes out of the rummaged nest.\n");
      say("A huge mosquito buzzes out of the rummaged nest.\n");
    }
    return 1;
  }
    write("Your search of the nests yields nothing.\n");  /* Rumplemintz */
    return 1;
  }
  if (str == "tracks")
  {
    write("The faint tracks go westward.\n");
    return 1;
  }
}


int listen(string str)
{
  write("The buzzing comes from some sort of insect.\n");
  return 1;
}
