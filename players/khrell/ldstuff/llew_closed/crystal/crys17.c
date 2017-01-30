inherit "room/room";

reset(arg) {
if(!arg) {
   short_desc="Blue Crystal";
   long_desc="\tBlue light reflects off of mirrored walls.  The light has no source,\n"+
      "but seems to eminate from the walls themselves.  Crystal walls in perfect\n"+
      "geometric symmetry rise around you with passages leading in many directions.\n"+
      "Melodic chimes can be heard from all directions.\n"+
      "\tSmall particles of blue-white light float about in seeming randomness.\n"+
      "They slip out of your graps at any attemp of capture, almost playfully taunting\n"+
      "you to catch them again.\n";
   dest_dir=({
      "/players/llew/closed/crystal/crys15.c","north",
      "/players/llew/closed/crystal/crys18.c","east",
      "/players/llew/closed/crystal/crys19.c","south",
      "/players/llew/closed/crystal/crys16.c","west",
      "/players/llew/closed/crystal/crys.c","up",
      "/players/llew/closed/crystal/crys20.c","down",
      });
   items=({
      "walls","You look at the mirrored walls and see your own reflection,\n"+
         "but it is not quite you.  It is yourself without any flaws. It is perfect.\n",
      "light","Glowing with warmth, it's hard not to smile when they pass in front\n"+
         "of your eyes.\n"});
}
}
