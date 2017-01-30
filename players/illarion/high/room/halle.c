inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="The entrance hall of the Dojo";
  long_desc=
"Unlike the outside of the building, this wood-floored hallway is fairly\n"+
"clean and well-maintained.  Concrete block walls border the way to the\n"+
"west and close off the hall to the east, where a few hooks are set in the\n"+
"wall.  To the north, a door opens onto the street.\n";
  items= ({
    "hallway","The place you currently occupy",
    "walls","Concrete block walls, unpainted but sturdy",
    "hooks","Probably for hanging coats on, but there are none there now",
    "door","A sturdy wooden door, with two deadbolts",
    "street","A dirty, dangerous, city street",
    "west","The hall ends near another doorway",
  });
  dest_dir= ({
    HROOM+"nystreet","out",
    HROOM+"hallw","west",
  });
}
