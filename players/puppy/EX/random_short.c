#include "/players/puppy/define.h"
iinherit "room/room";

reset(arg) {
   if(arg) return;
   
   set_long(
      "A room");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO \n",
         "item", "NO \n"});
   dest_dir = ({
         "/room/post.c", "out"});
   
   return 1; }

short() { int a; a = random(3);
   if (a==0) return ""+HIB+"A room"+NORM+" [out]";
   if (a==1) return ""+BLU+"A room"+NORM+" [out]";
   if (a==2) return ""+CYN+"A room"+NORM+" [out]";
}
