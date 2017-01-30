#include "/players/vertebraker/define.h"
#include "path.h"
inherit ROOM;

string *betas;

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = "Stable Feed Room "+GRN+"["+NORM+BOLD+"Knights Templar"+NORM+GRN+"]"+NORM;
   long_desc =
   "     A small window casts beams of sunlight through the dust laden air,\n"+
   "creating visible shafts of colored light which strike the floor at your\n"+
   "feet.  Brown burlap bags filled with grain are stacked along each wall\n"+
   "of the room from floor to ceiling.  Several bags are open and stand on\n"+
   "end in the center of the room, with oats and barley spilled around them\n"+
   "on the floor.  Empty leather feed bags are folded and stored upon a wide\n"+
   "wooden shelf running the length of the northern wall.\n";
   
   items = ({
         
         "window", "A dusty glass pained window with a wooden sash",
         "beams",  "Beams of sunlight from outside the window",
         "floor",  "Rough cut wooden boards joined close together",
         "bags",   "Sewn burlap with a draw string at one end",
         "grain",  "The grain is a mixture of oats and barley",
         "wall",   "The wall is made from thick cut wood planks",
         "ceiling","A low, thatched roof of grass and slender sticks",
         "shelf",  "A wide wooden shelf which holds empty feed bags", });
   add_exit(ROOMS+"s2","west");
   add_object(NPCDIR+"lindel");
   betas = ({ "aubergine", "handy", "pegasas", "lacar" });
}

init()
{
   ::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



realm() { return "LA"; }
