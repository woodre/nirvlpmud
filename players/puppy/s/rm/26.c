#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

int berry;
reset(arg) {
   berry = 0;
   if(arg) return;
   
   set_long(
      "Some bushes line the pathway leading to the south.  The opening\n"+
      "through the forest snakes around a curve and up to a large solid\n"+
      "mass.  That funny feeling that people get when they walk here is\n"+
      "caused by the dark clouds moving towards the south.\n");
   set_light(1);
   add_listen("main", "Strangely you hear nothing at all.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "pathway", "A path through the forest",
         "forest", "Many trees that have grown very tall", 
         "opening", "The exit to the south",
         "some bushes", "Some ripe blueberry bushes", 
         "bushes", "Some ripe blueberry bushes", 
         "curve", "The pathway that snakes around the forest floor",
         "large solid mass", "A dark structure to the south",
         "solid mass", "A dark structure to the south",
         "mass", "A dark structure to the south",
         "structure", "A tall menacing building that reaches into the sky",
         "dark clouds", "Black clouds moving to the south",
         "clouds", "Black clouds moving to the south",
         "trees", "Tall oak trees"});
   dest_dir = ({
         "/players/puppy/s/rm/27.c", "south",
         "/players/puppy/s/rm/23.c", "east"});
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
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [s,e]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [s,e]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [s,e]";
}
