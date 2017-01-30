#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_long(
      "Walking around the bend, it becomes quite clear where that\n"+
      "funny feeling in your stomach came from.  Before you stands\n"+
      "a dark castle partially masked by gray clouds.  No windows of\n"+
      "any kind can be seen from the outside of the castle.  A moat\n"+
      "filled with "+RED+"fluid"+NORM+" surrounds the building.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("liquid", "The odor from the liquid makes your nose crinkle.");
   items = ({
         "bend", "The curve that the pathway takes",
         "building", "A giant castle that stands before you",
         "moat", "A canal of flowing "+RED+"fluid"+NORM+" that surrounds the castle",
         "fluid", "Dark "+RED+"liquid"+NORM+" flowing through the moat",
         "gray clouds", "A mystical darkness in the air",
         "clouds", "A mystical darkness in the air",
         "dark castle", "A giant castle that stands before you",
         "castle", "A giant castle that stands before you.  You wonder if 'enter'ing it is a good idea"});
   dest_dir = ({
         "/players/puppy/s/rm/26.c", "north"});
   move_object(clone_object("/players/puppy/s/mob/azrael.c"), this_object());
   return 1; }

init(){
   ::init();
   add_action("ccastle", "enter");
}

ccastle(str){
   if(!str){ notify_fail("Enter what?\n"); return 0; }
   if(str == "castle" || str == "dark castle"){
      write("You enter the castle\n");
      this_player()->move_player("enters the dark castle#players/puppy/s/rm/28.c");
      return 1; }
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [n]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [n]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [n]";
}
