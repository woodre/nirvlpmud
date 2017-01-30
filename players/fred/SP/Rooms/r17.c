#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object garrison;
reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Class Room";
long_desc =
"  This is the classroom of the school.  There is a chalkboard on\n"+
"the wall and desks all around the room.  Sunlight pours through\n"+ 
"an open window casting a warm light on the room.\n"; 

items = ({
  "chalkboard",
  "The chalkboard is green in color and has chalk marks all over it.\n"+
  "The only thing you can read on it is 2+3= 7", 
  "sunlight",
  "Looking at the sunlight you notice all the dust in the air",
  "window",
  "From the open window you can see the parking lot outside",
  "wall",
  "They are painted white and have some crayon markings on them",
  "desks",
  "They are all placed in neat little rows throughout the room",   
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r15.c","exit",
  });
  garrison = clone_object("/players/fred/SP/Mon/mrg.c");
  move_object(garrison, this_object());
}
