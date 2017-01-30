inherit "room/room";
#include "definitions.h"


int d, e;


init()
{
  add_action("search","search");
  add_action("goplace","enter");
  ::init();
}


reset(arg)
{
  if (!present("sithi"))
  {
    for(d=1;d<=9;d++)
      move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"), this_object());
  }

  if (!present("knight"))
  {
    for(e=1;e<=2;e++)
      move_object(clone_object(CASTLEMONSTER+"/sithi_knight.c"), this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Guard barrecks";
    long_desc=
"     You enter a large room filled with wooden partitions and cots.\n"+
"Bags and wierd looking tools are stuffed into each partition.\n"+
"Each partition has a symbol upon it. Different symboled partitions\n"+
"have different sizes. This must be the home of all the temple\n"+
"residents, or at least one of the homes.\n";

    dest_dir=({
CASTLEROOM+"/room4.c","west"  ,
    });

    items=({
"cots",         "     They serve as moderately comfy beds",
"discoloration","     Perhaps this could be searched",
"partition",    "     Each partition serves as individual rooms for the Sithi.\n"+
                "In one partition, you notice a discoloration on the wall",
"partitions",   "     Each partition serves as individual rooms for the Sithi.\n"+
                "In one partition, you notice a discoloration on the wall",
    });
  }
}


search(str)
{
  if (!str)
  {
    write("What do you search?\n");
    return 1;
  }
  if (str == "walls")
  {
    write("What, all the walls in the entire room?\n");
    return 1;
  }
  if (str == "wall")
  {
    write("The whole wall? Anything in particular?\n");
    return 1;
  }
  if (str == "discoloration")
  {
    write(
"     You touch the wall and a section swings open. Just as it swings\n"+
"open, it closes again. You have discovered a trap doorway to another\n"+
"room. Type 'enter' to go through.\n");
    return 1;
  }
}


goplace()
{
  say(TPN+" enters a trap door.\n");
  write("You enter the trap door.\n\n");
  move_object(TP, "/players/dune/closed/castle/rooms/jao_tinukaii/armory");
  return 1;
}
