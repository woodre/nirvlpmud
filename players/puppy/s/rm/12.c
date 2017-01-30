#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
   if(arg) return;
   set_long(
      "Walking along the path, the most obvious thing that stands out\n"+
      "is a mushroom hut.  It has light blue curtains hanging from\n"+
      "its windows prevent people from seeing inside.  The entrance\n"+
      "to the hut is lighted by some fireflies.  Down the hill, the\n"+
      "the Smurflings are at play.\n");
   set_light(1);
   add_listen("main", "You hear the Smurflings playing.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "path", "A well worn path through the grass",
         "grass", "Lush blades of grass that have been worn down from all the traffic",
         "mushroom hut", "A hut made from a mushroom",
         "hut", "A hut made from a mushroom",
         "windows", "Windows in the hut that display light blue curtains",
         "light blue curtains", "Curtains that cover the windows",
         "blue curtains", "Curtains that cover the windows",
         "curtains", "Curtains that cover the windows",
         "entrance", "The place where you could 'enter' the hut",
         "hill", "The place where the land slopes sharply",
         "fireflies", "Little creatures that light your way"});
   dest_dir = ({
         "/players/puppy/s/rm/11.c", "west",
         "/players/puppy/s/rm/13.c", "east"});
   return 1; }

init(){
   ::init();
   add_action("hut", "enter");
}

hut(str){
   if(!str){ notify_fail("What are you trying to enter?\n"); return 0; }
   if(str == "hut") {
      this_player()->move_player("hut#players/puppy/s/rm/14.c");
      say(this_player()->query_name()+" enters the hut.\n");
      return 1;}
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [w,e]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [w,e]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [w,e]";
}
