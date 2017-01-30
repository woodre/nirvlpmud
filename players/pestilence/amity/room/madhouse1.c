#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }

short_desc = ""+BLU+"living room"+NORM+"";
long_desc =
  "    This is the living room of the house.  There is a large couch on\n"+
  "the west wall.  The carpet is a plush brown, with a few blood spots.\n"+
  "To the east there is a small bathroom, and to the north there is a\n"+
  "kitchen.  In the northwest corner there is a chair overturned.  The\n"+
  "television set is smashed.  Near the couch there is a stairway.\n";
set_light(1);

items = ({
"chair","A large plush chair turned upside down",
"couch","A brown couch sitting against the west wall",
"stairway","They are stairs leading up, and are covered in blue carpet",
"stairs","They lead up maybe you could climb them",
"carpet","A plush brown carpet covering the floor, with a few blood spots on it",
"bathroom","A small bathroom is to the east, you can't quite make out its details from here",
"television","A twenty-five inch television is smashed on the floor",
"walls","The walls are painted white with a few splashes of blood on them",
"west wall","The wall is painted white with a large couch pushed against it",
"spots",""+RED+"Red blood"+NORM+" spots left on the floor and walls from some viscious attack",
"blood spots",""+RED+"Red blood"+NORM+" spots left on the floor and walls from some viscious attack",
"blood",""+RED+"Red blood"+NORM+" spots left on the floor and walls from some viscious attack",
});

dest_dir = ({
  "/players/pestilence/amity/room/madison1.c","south",
  "/players/pestilence/amity/room/mad1kitchen.c","north",
  "/players/pestilence/amity/room/madhouse1bath.c","east",
});
}

init () {
   ::init() ;
     add_action ("climb_stairs","climb");
    add_action ("stairs","up");
     add_action ("stairs","u");
/*
     add_action ("stairs"); add_verb("u");
*/
     }

stairs() {
  write("Maybe you should 'climb stairs'.\n");
       return 1;
}

climb_stairs(arg) {
   if(!arg) { notify_fail("Climb what?\n");
       return 0;}

   if(arg == "stairs"){
     write("You climb the stairs.\n");
     TP->move_player("climb#/players/pestilence/amity/room/upmad1.c");
     return 1;}
else
{
       notify_fail("You may only climb the stairs.\n");
       return 0;
}
}
