#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

realm() { return "NT"; }
reset(arg) {
   if(!present("lazy"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/lazy.c"),this_object()); }}
   if(arg) return;
   
   set_long(
      "The forest thins out a bit here.  Two giant redwoods\n"+
      "dominate the area, making it one of the more shaded\n"+
      "places in Smurfville.  A comfortable looking hammock\n"+
      "is tied between the two trees.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "two giant redwoods", "Giant trees that are older then the Smurfs",
         "giant redwoods", "Giant trees that are older then the Smurfs",
         "redwoods", "Giant trees that are older then the Smurfs",
         "redwood", "A giant tree that has been here since before the time of the Smurfs",
         "two trees", "Giant trees that are older then the Smurfs",
         "trees", "Giant trees that are older then the Smurfs",
         "forest", "An area filled with giant redwood trees",
         "comfortable looking hammock", "A comfortable looking place to take a nap",
         "hammock", "A comfortable looking place to take a nap"});
   dest_dir = ({
         "/players/puppy/s/rm/22.c", "north",
         "/players/puppy/s/rm/20.c", "south",
         "/players/puppy/s/rm/18.c", "east"});
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [n,s,e]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [n,s,e]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [n,s,e]";
}
