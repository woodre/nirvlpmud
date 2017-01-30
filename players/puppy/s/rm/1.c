#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   
   set_long(
      "The view from this hill shows a few little mushroom huts with colorful\n"+
      "rooftops off in the distance. Movement from the town at the bottom\n"+
      "of the hill catches your eye.  A tree with some sort of structure at\n"+
      "the top stands high above the rest of the forest.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "hill", "A grassy hill",
         "little mushroom huts", "Colorful little huts",
         "mushroom huts", "Colorful little huts",
         "rooftops", "The tops of the little mushroom huts",
         "small town", "The place where colerful creatures reside", 
         "town", "The place where colorful creatures reside", 
         "forest", "The trees that make up the surrounding area of the village",
         "huts", "Colorful little huts",
         "large tree", "A tree off in the distance with a structure on top of it",
         "tree", "A tree off in the distance with a structure resting on it",
         "structure", "The structure is too far away to see in any detail"});
   dest_dir = ({
         "/players/puppy/areaentrance.c", "out",
         "/players/puppy/s/rm/2.c", "down"});
   
   return 1; }

short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [out,d]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [out,d]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [out,d]";
}
