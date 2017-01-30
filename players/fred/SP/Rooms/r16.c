#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object chef;
reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Lunch Room";
long_desc =
"  This is the lunch room where all the children come to eat.\n"+
"There are tables and chairs everywhere you look.  A poster\n"+
"hangs from the wall on your left.  From the scent in the air\n"+
"you can tell that it is salisbury steak day.\n"; 

items = ({
  "tables",
  "The tables are small and look like they need to be cleaned due\n"+
  "to the children", 
  "chairs",
  "Some of the chairs are knocked over and thrown off in the corner",
  "poster",
  "The poster reads: Milk is Nummy!", 
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r15.c","exit",
  });
  chef = clone_object("/players/fred/SP/Mon/chef.c");
  move_object(chef, this_object());
}
