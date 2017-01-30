#include "/players/fred/mages/defs.h"

inherit	"room/room";

reset(arg) { 
 if(!present("black book")) {
   MO(CO("/players/fred/mages/obj/blackbook.c"), TO);
 }
  if(!arg) {
  set_light(1);
  short_desc = "The Black Circle Fortress Entrance";
  long_desc = 
   "This is the entrance to the Black Circle Mages' stronghold.\n"+
   "Walls blacker than night surround you.  There is a large\n"+
   "black book here, perhaps you should take a look at it.\n";
  dest_dir = ({"players/fred/mages/rooms/advance", "north",
               "players/fred/forest/Rooms/entrance.c", "south"});
  }
}
init(){
  ::init();
   add_action("move_north","north");
   add_action("move_north","n");
}

move_north(){
 object ob;
 ob = present("dark_circle", TP);
 if(!ob){
   write("You must be a Black Circle Mage member to enter.\n");
   return 1; }
 TP->move_player("north#players/fred/mages/rooms/advance.c");
 return 1;
}
