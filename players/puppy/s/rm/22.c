#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

realm() { return "NT"; }
reset(arg) {
   if(!present("hefty"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/hefty.c"),this_object()); }}
   if(arg) return;
   
   set_long(
      "A flat parcel of land where the Smurf Olympics are held.  The\n"+
      "stone seats on the east side of the track have been carved out\n"+
      "of the side of a cliff.  To the west is the grandstand where\n"+
      "the Smurfs are judged on there abilities.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "stone seats", "Seats chiseled out of the side of a cliff",
         "seats", "Seats chiseled out of the side of a cliff",
         "side of the cliff", "A stone wall made into seats",
         "cliff", "A stone wall made into seats",
         "track", "The place where competitions are held",
         "grandstand", "A wooden structure high above the action on the track"});
   dest_dir = ({
         "/players/puppy/s/rm/21.c", "south",
         "/players/puppy/s/rm/19.c", "east"});
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [s,e]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [s,e]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [s,e]";
}
