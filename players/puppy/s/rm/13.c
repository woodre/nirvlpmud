#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_long(
      "Walking along the path, the most obvious thing that stands out\n"+
      "is a mushroom hut.  It has dark blue curtains hanging from\n"+
      "it's windows prevent people from seeing inside.  The entrance\n"+
      "to the hut is lighted by some fireflies.  Down the hill, the\n"+
      "the Smurflings are at play.\n");
   set_light(1);
   add_listen("main", "You hear the Smurflings playing.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "path", "A well worn path through the grass",
         "mushroom hut", "A hut made from a mushroom",
         "hut", "A hut made from a mushroom",
         "dark blue curtains", "Curtains that cover the windows",
         "blue curtains", "Curtains that cover the windows",
         "curtains", "Curtains that cover the windows",
         "windows", "Windows in the hut that display dark blue curtains",
         "hill", "The place where the land slopes sharply",
         "entrance", "The place where you could 'enter' the hut",
         "fireflies", "Little creatures that light your way"});
   dest_dir = ({
         "/players/puppy/s/rm/12.c", "west"});
   return 1; }

init(){
   ::init();
   { add_action("hut", "enter");}
}

hut(str){
   if(!str){ notify_fail("What are you trying to enter?\n"); return 0; }
   if(str == "hut") {
      this_player()->move_player("hut#players/puppy/s/rm/15.c");
      say(this_player()->query_name()+" enters the hut.\n");
      return 1;}
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [w]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [w]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [w]";
}
