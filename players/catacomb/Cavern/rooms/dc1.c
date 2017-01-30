#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
object person;

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc =HIB+"Shimmergloom's "+NORM+"cavern" ;
  long_desc =(
  "  A large cavern can be seen.  The cavern seems to\n"+
  "stretch forever.  Skeletons can be seen littered\n"+
  "throughout the cavern floor.  The walls are all \n"+
  "scorched and black.  The wall to the north is full\n"+
  "of cracks. \n"); 

  if(!present("shimmergloom"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/Sgloom.c"),
	    this_object());

  items = ({
    "skeleton",
    "The only remains of those foolish enough to enter the cavern", 
    "remains",
    "The only remains of those foolish enough to enter the cavern", 
    "floor",
    "Charred skeletons litter the floor",
    "walls",
    "The walls are scorched black",
    "wall",
    "The walls are scorched black",
    "crack",
    "A small crevice is formed to the north",
    "cracks",
    "A small crevice is formed to the north",
    "crevice",
    "It is almost big enough to 'squeeze' through"
  });
  
}
init()
{
  if(this_player() && this_player()->is_player())  
    /* if a player entered */
  {
    if(!person)  /* if person is  0 */
      person=this_player();
    else if(person != this_player())
    {
      tell_object(this_player(),
       "The rock will not move.\n");
      move_object(this_player(), "/players/catacomb/Cavern/rooms/lvl4_9.c");
      return;
    }
  }
  ::init();
     add_action("Move_shit","squeeze");
}

exit(ob)
{
  if(ob && ob->is_player())
  {
    if(person == ob)
      person=0;
  }
  ::exit(ob);
}

Move_shit(str)
{
  if (str != "crevice")
  {
    write("Squeeze through what?");
    return 1;
  }
  if (!present("shimmergloom"))
  {
    write("You squeeze through the crevice into the Durkor caverns.\n");
    TP->move_player("squeeze#players/catacomb/Cavern/rooms/lvl4_9.c");
    return 1;
  }
  else
  {
    write("Shimmergloom's mighty tail blocks the way.\n");
    return 1;
  }
}