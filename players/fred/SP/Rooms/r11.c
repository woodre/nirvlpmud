#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object kyle;
reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Kyle's House";
long_desc =
"  There is a large picture of Ike on the wall above the fireplace\n"+
"A lamp and a phone are sitting on an end table.  Sunlight is pouring\n"+  
"through the window creating a peaceful atmosphere.\n";

items = ({
  "picture",
  "A picture of Kyle's younger brother Ike", 
  "wall",
  "The walls are painted an off white color",
  "fireplace",
  "It has several pieces of burning wood in it and gives off\n"+
  "a nice warm heat",
  "phone",
  "The phone is white and Kyle's mom has the school and mayor's\n"+
  "numbers programmed into the speed dial",
  "lamp",
  "It is a porcelain lamp with a flower pattern painted on the base",
  "table",
  "It has many scratches and scuff marks on it",
  "window",
  "A large window that allows you to see children playing outside", 
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r10.c","out",
  });
  kyle = clone_object("/players/fred/SP/Mon/kyle.c");
  move_object(kyle, this_object());
}
