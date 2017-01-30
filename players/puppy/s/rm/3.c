#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

realm() { return "NT"; }
reset(arg) {
   if(!present("farmer"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/farmer.c"),this_object()); }}
   if(arg) return;
   
   set_long(
      "This field looks like it has been well cared for.  Someone\n"+
      "must spend a lot of time here working the earth and the\n"+
      "plants that grow in it.  Neatly planted rows of bushes\n"+
      "branch out for what seem like miles.\n");
   set_light(1);
   add_listen("main", "You hear laughter coming from the northeast.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "rows of bushes", "Small Smurfberry bushes",
         "bushes", "Small Smurfberry bushes",
         "field", "A well taken care of plot of land with lots of Smurfy plants",
         "earth", "A well taken care of plot of land with lots of Smurfy plants",
         "plants", "Lots and lots of Smurfy plants"});
   dest_dir = ({
         "/players/puppy/s/rm/2.c", "up",
         "/players/puppy/s/rm/4.c", "northeast",
         "/players/puppy/s/rm/9.c", "north",
         "/players/puppy/s/rm/8.c", "west"});
   return 1; }
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [u,ne,n,w]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [u,ne,n,w]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [u,ne,n,w]";
}
