#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

int berry;
reset(arg) {
   berry = 0;
   if(arg) return;
   
   set_long(
      "The little mushroom huts seem a bit bigger now.  There are a\n"+
      "few small bushes off the main path through the grass.  The\n"+
      "grass has been worn a little from all the people trying to have\n"+
      "a closer look at the bushes.  A small bird watches from the\n"+
      "trees above\n");
   set_light(1);
   add_smell("main", "You smell nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "mushroom huts", "Colorful little huts",
         "little mushroom huts", "Colorful little huts",
         "huts", "Colorful little huts",
         "grass", "Tiny blades of green vegetation that have been worn into a path",
         "crow", "A black crow perched high up in the trees staring down at you",
         "small bushes", "Small Smurfberry bushes that are not yet ripe",
         "rows of bushes", "Small Smurfberry bushes that are not yet ripe",
         "bushes", "Small Smurfberry bushes that are not yet ripe",
         "hill", "A grassy hill",
         "main path", "A grassy path leading away from the hill",
         "trees", "Tall trees that shade you from the sun",
         "small bird", "A black crow that is eyeing you",
         "bird", "A black crow that is eyeing you",
         "path", "A grassy path leading away from the hill"});
   dest_dir = ({
         "/players/puppy/s/rm/1.c", "up",
         "/players/puppy/s/rm/3.c", "down"});
   return 1; }

init(){
   ::init();
   add_action("search_bush","search");
}

search_bush(str){
   if(berry >=1){
      write("You search the bushes, but find nothing.\n");
      return 1; }
   if(str == "bushes" || str == "bush"){
      write("You find some blue berries in the bushes!\n");
      say(this_player()->query_name()+" finds some blue berries in a bush.\n");
      move_object(clone_object("/players/puppy/s/heal/berries.c"),this_player());
      berry +=1;
      return 1; }
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [u,d]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [u,d]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [u,d]";
}
