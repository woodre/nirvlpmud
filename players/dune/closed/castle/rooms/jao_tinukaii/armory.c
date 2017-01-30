inherit "room/room";
#include "definitions.h"


int armor;


init()
{
  add_action("search","search");
  ::init();
}


reset(arg)
{
  armor=0;

  if(!arg)
  {
    armor=0;
    set_light(0);
    short_desc="Armory";
    long_desc=
"     The secret passage opens up into small unlighted room. The air\n"+
"smells of rust, and as you look around, you see why. Swords, suits\n"+
"of armor, maces, and other pieces of armor lie in piles around the\n"+
"room. Too bad they appear all useless and rusty. Piles and piles,\n"+
"a shame...\n";

    dest_dir=({
CASTLEROOM+"/sithiguards.c","exit"  ,
    });

    items=({
"piles","     Perhaps these could be searched",
    });

  }
}


search(str)
{
  if (!str)
  {
    write("What do you search. Be more specific.\n");
    return 1;
  }

  str = lower_case(str);

  if (str == "piles")
  {
    if (armor==0)
    {
      write("You toss over the junk, and find a nice piece of armor.\n");
      write("It must really be special for it to last so long entact.\n");
      move_object(clone_object(CASTLEOBJECT+"/armor.c"),this_object());
      armor=1;
    }
    else write("The piles have already been searched.\n");
    return 1;
  }
}
