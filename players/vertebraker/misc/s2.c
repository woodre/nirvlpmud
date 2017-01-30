#include "/players/vertebraker/define.h"
#include "path.h"

inherit ROOM;

string *betas;
reset(x) {
   if(x) return;
   betas = ({ "aubergine", "pegasas", "lacar", "handy", "guineapig", "verte" });
   set_light(1);
   short_desc = "The Stables "+GRN+"["+NORM+BOLD+"Knights Templar"+NORM+GRN+"]"+NORM;
   long_desc =
   "     Small piles of straw mixed with horse dung are piled up\n"+
   "near the door waiting to be loaded on a cart.  Stalls run the\n"+
   "length of the main stable area with gates opening into a center\n"+
   "walkway.  Braided lead ropes are coiled and hung at each stall,\n"+
   "and various types of tack hang here and there from wooden pegs.\n"+
   "Colorful banners hang from the gate of each stall, signifying\n"+
   "the Knight to which each horse belongs.\n";
   items = ({
         "ground", "Brown dirt mixed with horse-dung, straw, and sawdust",
         "stalls", "Horse stalls.  They line the wall of the stable",
         "door",   "The stable door is open on both sides and tied off with\n"+
         "a piece of rope",
         "shoe",   "An old horse shoe that has seen many years of rain and sun",  
         "ropes","Long ropes hang from each stall",
         "stall","Each stall you look at contains a beautiful riding horse",
         "tack","Ropes and nails hang here from the walls",
         "walls","The walls are lined with an assortment of tack for the horses",
         "banners","Colorful banners with names on them",
         "names","Various names of knights", });
   add_object(NPCDIR+"harker");
   add_object("/players/maledicta/hope/mobs/templar_guard2");
   add_object(NPCDIR+"simon");
   add_item(({"straw","piles","dung","horse dung",}),
      "Small tufts of straw and horse dung are intermixed here,\n"+
      "creating an odious backdrop to the stable");
   add_smell("main","You smell.. ew.. poo?\n"+
      "Your olfactory senses reel in observation!");
   dest_dir = ({
         ROOMS+"s3.c","east",
         ROOMS + "h/super_storage", "south",
         ROOMS+"s1.c","leave", });
}

init()
{
   ::init();
   add_action("syntax","out");
}

syntax()
{
   if(!TP) return;
   command("leave",TP);
   return 1;
}

leave()
{
   write("  You walk back to the stable yard...\n\n");
}

realm() { return "LA"; }
