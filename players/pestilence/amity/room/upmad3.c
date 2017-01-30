#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }

short_desc = ""+BLU+"Main Bedroom"+NORM+"";
long_desc =
  "    This is a small bedroom on the western side of the house.\n"+
  "There is a red carpet on the floor.  Two dressers are against the\n"+
  "wall on the west.  The door is on the east.  There is a large bed\n"+
  "in the middle of the room, with some clothes scattered over it.\n"+
  "The nightstand next to the bed has been tipped over.  There is a\n"+
  "closet on the north end of the room, with the door slightly open.\n";
set_light(1);

items = ({
"closet","A very small closet that you could enter",
"bed","A large bed with a dark blue comforter and two large fluffy pillows",
"dressers","Two wooden dressers, with the finish worn",
"carpet","A red carpet extends from wall to wall",
"nightstand","A small nightstand tipped over during a struggle",
});

dest_dir = ({
  "/players/pestilence/amity/room/upmad1.c","east",
});
}

init () {
   ::init() ;
   add_action ("enter_closet","enter");
     }

enter_closet(arg) {
   if(!arg) { notify_fail("Enter what?\n");
       return 0;}
   if(arg == "closet"){
     write("You slide open the door and go into the closet.\n");
     TP->move_player("enter#/players/pestilence/amity/room/upmad1closet.c");
     return 1;}
else
{
       notify_fail("You may only enter the closet\n");
       return 0;
}
}
