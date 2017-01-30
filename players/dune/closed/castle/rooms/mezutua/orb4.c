inherit "room/room";
#include "definitions.h"


int presentorb;

init()
{
  add_action("search","search");
  add_action("remove","remove");
  ::init();
}

reset(arg)
{
  presentorb = 1;

  if(!arg)
  {
    set_light(0);
    short_desc=("Orb Room");
    long_desc=
"     A spacious room of sparkling limestone walls blesses your travel\n"+
"weary eyes. Upon the floor, several words are engraved. In the middle\n"+
"of the room rests a glass pedestal.\n";

    dest_dir=({
CASTLEROOM+"/spout4.c","south"  ,
CASTLEROOM+"/spout3.c","west"  ,
    });

    items=({
"pedestal","     Perhaps you should search this",
"words",   "     You take a look at the engraved words.\n"+
           "A look and you will see,\n"+
           "What others think you to be.\n"+
           "The words lie engraved upon a field of glass",
    });
  }
}


search(string str)
{
  if (!str) return 0;
  str = lower_case(str);
  if (str != "pedestal") return 0;
  if (presentorb == 1)
  {
     write("You uncover a latch and discover an orb inside!\n");
     write("You wonder if you should remove it.\n");
     return 1;
  }
  write("You can find nothing in the pedestal.\n");
  return 1;
}


int remove(string str)
{
  if (!str)
  {
    write("Remove what from what?\n");
    return 1;
  }

  str = lower_case(str);

  if (str == "orb from pedestal" || 
      str == "orb from the pedestal")
  {
    if (presentorb == 1)
    {
      presentorb = 0;
      write("You remove the orb from the pedestal.\n");
      move_object(clone_object(CASTLEOBJECT+"/orbobj4.c"),this_player());
      write_file("/players/dune/log/QUEST_OBJ", this_player()->query_real_name()+
                 " (level "+this_player()->query_level()+
                 ") took the Glass Orb. ("+ctime()+")\n");
      return 1;
    }
    write("There is no orb on the pedestal.\n");
    return 1;
  }

  write("Removing that does not make sense!\n"+
        "Remove what from what?\n");
  return 1;
}
