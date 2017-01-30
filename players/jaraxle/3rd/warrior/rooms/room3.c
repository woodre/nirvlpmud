#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = "Third Earth";
   long_desc =
   "  The forest closes in to the north with an intimidating\n"+
   "growth of trees.  The ground rolls over like a soft sunset wave\n"+
   "in uneven patterns eastward.  There is a bundle of sticks oddly\n"+
   "gathered together in the northwestern direction.\n";
   
   items = ({
         "forest","A tall wall of trees enclose you to the north",
         "trees","High reaching trees with thick branches stretching out everywhere.\nThere is a sliver of "+HIW+"darkness"+NORM+" between two of the trees",
         "bundle","A bundle of sticks",
         "darkness","An eerie dark shadow cast between two trees.\nIt looks like you can go northeast through the shadows",
         "branches","Large branches which grow low to the ground",
         "ground","The ground seems to flow to the east in a movement of small humps and hills",
         "sticks","These 'sticks' are actually arrows",
         "arrows","A small quiver of arrows, covered slightly with old moss",
         "moss","Old gray moss",
});
   
   MOCO("/players/jaraxle/3rd/warrior/mon/boy.c"),TO);
dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/roomw3.c","west",
  "/players/jaraxle/3rd/warrior/rooms/roome3.c","east",
  "/players/jaraxle/3rd/warrior/rooms/room2","south",
/*
   "/players/jaraxle/cont/ltown/rooms/l1.c","north",
*/
  "/players/jaraxle/3rd/warrior/rooms/roomw2.c","southwest",
  "/players/jaraxle/3rd/warrior/rooms/roome2.c","southeast",
});

}

init() {

::init();

add_action("go_ne","ne");
add_action("go_ne","northeast");
}
go_ne(){
write("You sneak through the shadows into the northeast.\n");
this_player()->move_player(".#/players/jaraxle/3rd/alt/rooms/entrance.c");
return 1; }
