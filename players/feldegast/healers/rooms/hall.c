#include "def.h"

inherit ROOM;

reset(arg) 
{
  if(!present("board")) 
  {
    object board;
    board=clone_object("/players/feldegast/std/board");
    board->set_file(PATH+"board");
    move_object(board,this_object());
  }

  if(arg) return;

  set_no_teleport(1);

  set_light(1);

  short_desc=AREANAME;

  long_desc=
    "  Marble tiles line the floor of this wide hall.  A pair of long, low\n"+
    "tables surrounded by mahogany chairs run the length of the room.  A\n"+
    "fire crackles in the stone hearth in the north wall.  Above it is an\n"+
    "antique clock.  On either side of the hearth are a pair of doors which\n"+
    "lead out into the garden.  The smell of baking bread and roasted meat\n"+
    "comes from the door to the west.  There is also a door to the east and\n"+
    "an archway leads south out of the compound.\n";

  items=({
    "tiles","Tiles made out of blue marble striped with black",
    "tables","Beautifully crafted antique tables made out of mahogany",
    "fire","The fire gives a warm homey quality to the hall",
    "hearth","The fireplace is made out of ancient rounded stone",
    "clock","See long(str) for details",
  });

  dest_dir=({
    ROOMPATH+"garden1","north",
    ROOMPATH+"kitchen","west",
    ROOMPATH+"east_hall","east",
    "/players/feldegast/realm/Caladon/3x6.c","out"
  });
}

long(str) {
  if(str=="clock") {
    write("The clock says: "+ctime(time())+".\n");
    say(TPN+" looks at the antique clock above the hearth.\n");
  }
  else ::long(str);
}

