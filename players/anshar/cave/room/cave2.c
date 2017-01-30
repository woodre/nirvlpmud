#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return;
  set_light(0);
  short_desc="A dark cave";
  long_desc=
"     The debris that littered the entrance to the cave has been kept  \n"+
out of this area. Cold stone walls drip water with a constant sound.  \n"+
The stench is stronger here, but seems to emanate from deeper within  \n"+
the cavern.\n";
  items =
  ({
    "walls",       "Dark granite walls, beaded with moisture",
    "water",       "Moisture drips down the walls in dark, cool rivulets",
    "moisture",    "Moisture drips down the walls in dark, cool rivulets",
    "rivulets",    "Moisture drips down the walls in dark, cool rivulets",
    "cavern",      "Burrowing deep within the mountain, a light flickers deeper inside",
  });
  dest_dir =
  ({
    CROOM+"cave3", "south",
    CROOM+"cave1", "out",
  });
  if(!present("bear"))
  {
    move_object(clone_object(CMON+"cbear"),this_object());
    move_object(clone_object(CMON+"cbear"),this_object());
    move_object(clone_object(CMON+"cbear"),this_object());
    move_object(clone_object(CMON+"cbear"),this_object());
  }
}

init()
{
  ::init();
  add_action("south","south");
}

south()
{
  if(present("bear"))
  {
    write("The bear is in your way.\n"); 
    say("The bear prevents " + this_player()->query_name() +
      " from going south.\n");
    present("bear",this_object())->attack_object(this_player());
    return 1;
  }
  this_player()->move_player("south#/players/anshar/cave/room/cave3");
  return 1; 
}
