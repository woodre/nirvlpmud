#include "/sys/lib.h"
#include "/players/pestilence/define.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+YEL+"Cahara's Cave"+NORM+"";
long_desc =
  "    This is a larger part of the cavern. It is quite dark, and would be\n"+
  "totally dark if not for the small amount of light coming through a small\n"+
  "hole on the north wall.  The cavern continues to the east and south.\n"+
  "The other directions are solid rock.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/cave.c","south",
});

}
init () {
   ::init() ;
     add_action ("enter_hole","enter");
     }

enter_hole(str) {
   if(str != "hole") { write("Open what?\n");
       return 1;}

     write("You struggle through the hole.\n");
     this_player()->move_player("enter#/players/pestilence/Cahara/room/bwaterfall.c");
     return 1;}
