#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object officer;
reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "South Park";
long_desc =
"  You notice as you keep going east that the city starts to look\n"+
"more rundown.  Some people are hurriedly crossing the street up\n"+  
"ahead and there are some houses off to the east. A side street\n"+
"heads towards the north of town.\n";

items = ({
  "people",
  "An older couple trying to cross the road before the light changes", 
  "street",
  "The street is made of smooth black asphalt", 
  "houses",
  "There are some houses off to the east but you can't quite see them clearly",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r4.c","west",
  "/players/fred/SP/Rooms/r6.c","east",
  "/players/fred/SP/Rooms/r18.c","north",
  });
  officer = clone_object("/players/fred/SP/Mon/bbrady.c");
  move_object(officer, this_object());
}
