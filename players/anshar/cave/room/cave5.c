#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(1);
  short_desc="A dark cave";
  long_desc=
"     This large open cavern is lit by a natural chimney through which\n\
light streams. There are boulders piled along the south end of the room\n\
in large, neat stacks. This place has a lived in look, with a fire in\n\
the center and sleeping pallets to the side.The stench of rotten meat\n\
attests to the dietary habits of the inhabitants.\n";
  items =
  ({
    "cavern",      "Large and open, this is the largest area in the complex",
    "chimney",     "A single hole through which sunlight lights the area",
    "hole",        "A single hole through which sunlight lights the area",
    "boulders",    "Large head-sized rocks piled neatly",
    "stacks",      "Large head-sized rocks piled neatly",
    "fire",        "A fire, lain obviously, more for warmth than cooking, based on the stench",
    "pallets",     "Dirty, worthless hides, for sleeping",
    "hides",       "Dirty, worthless hides, for sleeping",
  });
  dest_dir =
  ({
    CROOM+"cave3", "north",
    CROOM+"cave6", "south",
  });
  if(!present("giant"))
  {
    move_object(clone_object(CMON+"sgiant1"),this_object());
    move_object(clone_object(CMON+"sgiant1"),this_object());
    move_object(clone_object(CMON+"sgiant2"),this_object());
    move_object(clone_object(CMON+"sgiant2"),this_object());
    move_object(clone_object(CMON+"sgiant2"),this_object());
    move_object(clone_object(CMON+"sgiant2"),this_object());
  }
}

init()
{
  ::init();
  add_action("south","south");
}

south()
{
  if(present("giant"))
  { 
    write("You cannot get around the boulders with a giant in the room.\n"); 
    say("A giant prevents "+this_player()->query_name()+" from going south.\n");
    return 1;
  }
  this_player()->move_player("south#/players/anshar/cave/room/cave6");
  return 1; 
}
