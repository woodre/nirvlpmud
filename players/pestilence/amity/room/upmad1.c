#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }

if (!present("ant 2")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }

short_desc = ""+BLU+"Top of the Stairs"+NORM+"";
long_desc =
  "    This is a small hallway at the top of the stairs.  There is a\n"+
  "brown carpet on the floor here.  There are two rooms to the east\n"+
  "and west of here.  The stairs go back downstairs to the living room.\n"+
  "The walls are covered with a brown paneling, with black stripes\n"+
  "every sixteen inches.\n";
set_light(1);

items = ({
"walls","The walls are covered with brown paneling with black stripes",
"floor","A flat brown carpet covers the floor from wall to wall",
"stripe","Black stripe running down the paneling",
"stripes","Black stripes running down the paneling",
"rooms","Bedrooms to the east and west",
"paneling","The paneling is brown with black stripes",
"stairway","They are stairs leading down, and are covered in blue carpet",
"carpet","Flat brown carpet goes from wall to wall",
"stairs","They lead down, maybe you could climb them",
});

dest_dir = ({
  "/players/pestilence/amity/room/upmad2.c","east",
  "/players/pestilence/amity/room/upmad3.c","west",
});
}

init () {
   ::init() ;
     add_action ("climb_stairs","climb");
    add_action ("stairs","down");
     add_action ("stairs","d");
     }

stairs() {
  write("Maybe you should 'climb stairs'.\n");
       return 1;
}

climb_stairs(arg) {
   if(!arg) { notify_fail("Climb where?\n");
       return 0;}
   if (arg == "stairs"){
     write("You climb the stairs.\n");
     TP->move_player("climb#/players/pestilence/amity/room/madhouse1.c");
     return 1;}
else
{
       notify_fail("You may only climb the stairs.\n");
       return 0;
}
}
