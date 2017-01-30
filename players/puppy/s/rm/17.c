#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

realm() { return "NT"; }
reset(arg) {
   if(!present("grandpa"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/grandpa.c"),this_object()); }}
   if(arg) return;
   
   set_long(
      "An old rocking chair rests atop a colorful rug in the center\n"+
      "of the room.  The stand next to the chair holds a small\n"+
      "reading lamp.  Many tiny knickknacks are hung up on the\n"+
      "walls.  Hanging on the coat rack in the corner of the\n"+ 
      "room is a blue sweater.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "knickknacks", "Lots of artsy things that Grandpa Smurf has collected",
         "room", "Papa Smurfs residence",
         "floor", "The dirt area where everything rests in the room",
         "old rocking chair", "Grandpa Smurfs favorite place to relax",
         "rocking chair", "Grandpa Smurfs favorite place to relax",
         "chair", "Grandpa Smurfs favorite place to relax",
         "colerful rug", "A covering for the cold floor",
         "rug", "A covering for the cold floor",
         "stand", "A wooden table with a small reading lamp resting on it",
         "small reading lamp", "A light source that helps Grandpa Smurf save his eyes",
         "reading lamp", "A light source that helps Grandpa Smurf save his eyes",
         "lamp", "A light source that helps Grandpa Smurf save his eyes",
         "coat rack", "A place to hang ones garments",
         "rack", "A place to hang ones garments",
         "blue sweater", "A garment to help keep Grandpa Smurf warm",
         "sweater", "A garment to help keep Grandpa Smurf warm",
         "walls", "The sides of the hut lined with knickknacks"});
   dest_dir = ({
         "/players/puppy/s/rm/18.c", "north",
         "/players/puppy/s/rm/20.c", "west",
         "/players/puppy/s/rm/9.c", "east"});
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [n,w,e]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [n,w,e]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [n,w,e]";
}
