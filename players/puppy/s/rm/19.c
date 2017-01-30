#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

realm() { return "NT"; }
reset(arg) {
   if(!present("jokey"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/jokey.c"),this_object()); }}
   if(arg) return;
   
   set_long(
      "The trees here seem shorter then the others in this forest.\n"+
      "Stacks of unwrapped boxes rest against a large boulder.  Some\n"+
      "paper and ribbons have been thrown about the ground.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "stacks of unwrapped boxes", "Little gift packages created by Jokey Smurf",
         "unwrapped boxes", "Little gift packages created by Jokey Smurf",
         "boxes", "Little gift packages created by Jokey Smurf",
         "stacks", "Little gift packages created by Jokey Smurf",
         "sawdust", "Little shavings from Handy Smurfs creations",
         "forest", "All of the plantlife that surrounds you",
         "large boulder", "A huge piece of stone",
         "boulder", "A huge piece of stone",
         "ground", "The floor that is piled with lots of wraping material",
         "paper", "Piles of shiny wrapping",
         "ribbons", "Colorful strands that are used to secure the wrapping over boxes",
         "trees", "Oak trees that reach into the sky"});
   dest_dir = ({
         "/players/puppy/s/rm/18.c", "south",
         "/players/puppy/s/rm/22.c", "west",
         "/players/puppy/s/rm/11.c", "east"});
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [s,w,e]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [s,w,e]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [s,w,e]";
}
