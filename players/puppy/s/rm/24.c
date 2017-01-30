#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short("The top of a tree");
   set_long(
      "From this perch, a view of the whole village can be seen.\n"+
      "Looking through the treetops, the ground seems very far away.\n"+
      "Behind a pile of leaves something that glimmers catches your\n"+
      "eye.  Overhead is a small rope tied to something behind\n"+
      "the leaves.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "ground", "The ground seems very far away",
         "village", "Small huts that make a perfect circle can be seen from here",
         "view", "A small village at the bottom of the hill can be seen from here",
         "vine", "A strand of vegetation hanging from the tree",
         "trees", "The tops of the trees that are far below you",
         "treetops", "The tops of the forest",
         "pile of leaves", "A pile of leaves that seem to cover up something",
         "something", "Um, What would you like to look at",
         "spaceship", "A makeshift spaceship.  You wonder what could be in it",
         "makeshift spaceship", "A makeshift spaceship.  You wonder what could be in it",
         "ship", "A makeshift spaceship.  You wonder what could be in it",
         "small rope", "Woven pieces of vine tied to something behind a pile of leaves",
         "rope", "Woven pieces of vine tied to something behind a pile of leaves",
         "pile of leaves", "A pile of leaves that seem to cover up something",
         "pile", "A pile of leaves that seem to cover up something",
         "leaves", "A pile of leaves that seem to cover up something"});
   dest_dir = ({
         "/players/puppy/s/rm/23.c", "out"});
   return 1; }

init() 
{
   ::init(); 
   add_action("ship","enter");
   add_action("leaves", "search");
   add_action("rope", "pull");
}

leaves(str) {
   if(!str){ notify_fail("What are you looking for?\n"); return 0; }
   if(str == "leaves" || str == "pile of leaves" || str == "a pile of leaves") {
      write("You find a makeshift spaceship covered in a pile of leaves!\n");
      say(this_player()->query_name()+ " searches through the pile of leaves.\n");
      return 1;   }
}
rope(str) {
   if(!str){ notify_fail("What are you going to pull?\n"); return 0; }
   if(str == "rope" || str == "vines") {
      write("The rope is attached to something heavy and can not be pulled.\n");
      return 1; }
}
ship(str) {
   if(!str){ notify_fail("What are you trying to enter?\n"); return 0; }
   if(str == "ship" || "spaceship") {
      write("You enter the ship.\n");
      say(this_player()->query_name()+" enters the ship.\n");
      this_player()->move_player("into the ship#players/puppy/s/rm/25.c");
      return 1; }
}
