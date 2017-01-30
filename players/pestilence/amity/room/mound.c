#include "/open/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/guard2.c"),
        this_object()); }

short_desc = ""+YEL+"Large Mound"+NORM+"";
long_desc =
  "    This is the top of a large mound of dirt.  It has been made by\n"+
  "hundreds of ants.  There is a large hole in the middle of the mound,\n"+
  "that leads deep into the ground.  Blood surrounds the hole.  The\n"+
  "south leads back to the path, and in all of the other directions the\n"+
  "mound is too high to navigate successfully.\n";
set_light(1);

items = ({
"dirt","A large pile of dirt forming a mound",
"hole","A large hole leading into the depths of the mound",
"blood","Blood spots cover the ground around the hole",
"path","A worn path leads back to the street",
"mound","A large pile of dirt forming a large mound",
});

dest_dir = ({
  "/players/pestilence/amity/room/path.c","south",
});
}

init () {
   ::init() ;
     add_action ("enter_hole","enter");
     }

enter_hole(arg) {
   if(!arg) { notify_fail("Enter what?\n");
       return 0;}  
   if (arg == "hole"){
     write("You enter the ant's mound.\n");
     TP->move_player("enter#/players/pestilence/amity/room/tun1.c");
  command("look",this_player());
     return 1;}
   else
{
       notify_fail("You may only enter the hole.\n");
       return 0;
}
}
