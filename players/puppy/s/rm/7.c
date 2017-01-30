#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(""+CYN+"Smurfville playground"+NORM+"");
   set_long(
      "The shade from the pine tree makes a perfect place to sit and\n"+
      "relax away from the sun.  Arranged against the hill is a pile\n"+
      "of leaves.  Down the hill is where the grassy field meets the\n"+  
      "rest of town.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "shade", "A darkened area that blocks out the sun",
         "town", "Small huts at the bottom of the hill",
         "smal huts", "Little dwellings that the Smurfs live in",
         "small huts", "Little dwellings that the Smurfs live in",
         "huts", "Little dwellings that the Smurfs live in",
         "field", "A small plot of land just outside the town where the crops are grown",
         "pine tree", "A tall tree that reaches into the sky",
         "pine", "A tall tree that reaches into the sky",
         "tree", "A tall tree that reaches into the sky",
         "sun", "A bright ball of light high in the sky",
         "hill", "The ground that leads up to some huts",
         "pile of leaves", "Leaves laid out as bedding",
         "pile", "Leaves laid out as bedding",
         "leaves", "Leaves laid out as bedding"});
   dest_dir = ({
         "/players/puppy/s/rm/6.c", "east",
         "/players/puppy/s/rm/4.c", "south"});
   move_object(clone_object("/players/puppy/s/mob/baby/slouchy.c"), this_object());
   return 1; }
