#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_long(
      "The sunlight here seems to fade a bit.  To the west, some dark\n"+
      "clouds make it seem a lot darker then the rest of Smurfville.\n"+
      "Next to a large oak tree, the path narrows almost as if people\n"+
      "are afraid to pass.  The rocky path ends here.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "dark clouds", "A large mass in the sky",
         "clouds", "A large mass in the sky",
         "large oak tree", "A tall tree that you wonder if you could climb",
         "oak tree", "A tall tree that you wonder if you could climb",
         "tree", "A tall tree that you wonder if you could climb",
         "stream", "A stream that seems to divide the villiage",
         "sunlight", "The light coming from the sky",
         "oak", "A tall tree that you wonder if you could climb",
         "rocks", "Large boulders that litter the ground", 
         "rocky path", "Rocks that form a path from the stream to the woods",
         "path", "Rocks that form a path from the stream to the woods"});
   dest_dir = ({
         "/players/puppy/s/rm/26.c", "west"});
   return 1; }

init()
{
   ::init();
   add_action("ttree", "climb");
   add_action("rrocks", "walk");
}

rrocks(str) {
   if(!str){ notify_fail("Where would you like to walk?\n"); return 0; }
   if(str == "rocks")  {
      write("You walk back across the stream.\n");
      this_player()->move_player("across the stream#players/puppy/s/rm/20.c");
      return 1; }
}

ttree(str) {
   if(!str){ notify_fail("What are you trying to climb?\n"); return 0; }
   if(str == "tree")  {
      write("You grab a branch and pull yourself up into the tree\n");
      this_player()->move_player("up the tree#players/puppy/s/rm/24.c");
      return 1; }
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [w]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [w]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [w]";
}
