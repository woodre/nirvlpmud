#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg) {

   if(!arg) {
   short_desc="Blue Crystal";
   long_desc="\tBlackness surrounds you.  The crystal walls give no reflection.\n"+
         "Here all is nothing, gone...\n";
   dest_dir=({
      "/players/llew/closed/crystal/crys20.c","up",
      "/players/llew/closed/crystal/crys22.c","down",
      });
   items=({
      "blackness","You don't see anything.\n",
   });
   }
   
   mon_reset();
}


mon_reset() {
   object *ri;
   int amm,x;
   ri = all_inventory(this_object());
   for(x=0; sizeof(ri) > x; x++) {
      if(ri[x]->query_name() == "xetra") amm++;
   }
   while(amm<3) {
   move_object(clone_object("/players/llew/closed/crystal/demon2.c"),this_object());
      amm++;
   }
}

init() {
   ::init();
   add_action("down","down");
   add_action("down","d");
}

down() {
   if(present("xetra")) {
      write("The Xetra blocks your passage down.\n");
      return 1;
   }
}
