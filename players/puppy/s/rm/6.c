#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(""+CYN+"Smurfville playground"+NORM+"");
   set_long(
      "A large pine tree with drooping branches stands directly in\n"+ 
      "the path.  Resting on the branches is a tiny tree fort with\n"+
      "a ladder and swing attached.  Down the hill is a grassy\n"+
      "field where the Smurflings play.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "pine tree", "A tall tree that reaches into the sky", 
         "pine", "A tall tree that reaches into the sky",
         "tree", "A tall tree that reaches into the sky", 
         "tiny tree fort", "A very small fort that will only hold the Smurflings",
         "tree fort", "A very small fort that will only hold the Smurflings",
         "fort", "A very small fort that will only hold the Smurflings",
         "swing", "A swing made from vines and a piece of wood",
         "ladder", "Branches tied against the side of the fort that allow the Smurflings a way to enter the tiny tree fort",
         "hill", "A steep hill leading south", 
         "vines", "Strands of vetetation that hold up the swing",
         "vine", "Strands of vetetation that hold up the swing",
         "path", "The walkway through the forest that is traveled by many",
         "grassy field", "A small field covered in grass",
         "field", "A small field covered in grass",
         "drooping branches", "Branches that hang down from the pine tree",
         "branches", "Branches that hang down from the pine tree"});
   dest_dir = ({
         "/players/puppy/s/rm/7.c", "west",
         "/players/puppy/s/rm/5.c", "south"});
   move_object(clone_object("/players/puppy/s/mob/baby/snap.c"), this_object());
   return 1; }

init(){
   ::init();
   { add_action("lladder", "climb"); }
}

lladder(str) {
   if(!str){ notify_fail("What are you trying to climb?\n"); return 0; }
   if(str == "ladder") {
      write("You try to grab onto the rung of the ladder but an unknown forces pushes your hand away.\n");
      say(this_player()->query_name()+ " looks to the top of the ladder.\n");
      return 1; }
}
