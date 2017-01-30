inherit "room/room";
#include "definitions.h"


int i;
int j;

reset(arg)
{
  if (!present("frog"))
  {
    for (i=1;i<=3;i++)
      move_object(clone_object(CASTLEMONSTER+"/frogs.c"),this_object());
  }
  if (!present("snake"))
  {
    for (j=1;j<=5;j++)
      move_object(clone_object(CASTLEMONSTER+"/snakes.c"),this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Bog";
    long_desc=
"     A series of thick bushes give way to a large circular bog. A thin\n"+
"layer of mist obscures patches of the ground. Long thick curtains of moss\n"+
"drape from the twisted white skinned trees. The air is especially stale in\n"+
"here, with no wind or fresh air ever penetrating this secluded bog. Several\n"+
"large holes are dug into the tree roots. It would be a perfect hiding\n"+
"place for hideous swamp fiends.\n";

    dest_dir=({
        CASTLEROOM+"/1sw1.c","northeast"  ,
    });

    items=({
"moss",  "     The green moss gathers in large clumps",
"holes", "     The holes might house some nasty beasties",
"mist",  "     The mist swirls, like there is motion underneath",
"bushes","     The bushes block out all further vision",
"bog",   "     The bog is quite large",
"trees", "     The trees are strangely discolored, perhaps from lack of proper\n"+
         "sunlight. Their leaves are wilted and decayed",
    });
  }
}
