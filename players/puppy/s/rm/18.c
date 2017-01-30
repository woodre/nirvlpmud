#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

realm() { return "NT"; }
reset(arg) {
   if(!present("hefty"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/hefty.c"),this_object()); }}
   if(arg) return;
   
   set_long(
      "A small clearing in the woods where the creatures of this\n"+ 
      "villiage come to work-out.  A fallen log under a tree serves\n"+
      "as an unconventional workout bench.  Vines hanging down from\n"+
      "one of the branches provide another place to hone one's skills.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "fallen log", "A very old tree that fell in a storm",
         "log", "A very old tree that fell in a storm",
         "vines", "A long strands of vegetation",
         "clearing", "An open space in the middle of the woods",
         "woods", "The area that has many trees that have been here for years",
         "tree", "One of the many trees in this forest",
         "vine", "A vine that hangs down from one of the trees branches",
         "branches", "A limb of the tree"});
   dest_dir = ({
         "/players/puppy/s/rm/17.c", "hut",
         "/players/puppy/s/rm/19.c", "north",
         "/players/puppy/s/rm/10.c", "east",
         "/players/puppy/s/rm/21.c", "west"});
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [hut,s,w,e]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [hut,s,w,e]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [hut,s,w,e]";
}
