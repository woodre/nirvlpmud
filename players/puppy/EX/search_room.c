#include "/players/puppy/define.h"
inherit "room/room";

int berry; /* This will be a # we want to use so players cannot get endless berries */
reset(arg) {
   berry = 0; /* When the room resets, the intiger will be 0 */
   if(arg) return;
   
   set_short("This is the short");
   set_long("This is the description.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "room/post.c","out",
         "room/post.c", "out"});
   move_object(clone_object("/players/puppy/EX/mob.c"), this_object());
   return 1; }

init(){
   ::init();
   add_action("search_bush","search");
}

search_bush(str){
   if(berry >=1){ /* If the intiger is greater than, or equal to 1 */
      write("You search the bushes, but find nothing.\n"); /* No berries left */
      return 1; } /* make it true */
   if(str == "bushes" || str == "bush"){  /* if they type 'search bush' or 'search bushes' */
         write("You find some berries in the bushes!\n");
      say(this_player()->query_name()+" finds some berries in a bush.\n");
      /* Tell them they found something */
      move_object(clone_object("/players/puppy/s/heal/berries.c"),this_player()); /* move some berries to a player */
      berry +=1; /* make the intiger for berries add 1 to the previous number of the intiger */
      return 1; } /* make this statement true */
}
