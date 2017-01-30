#include "/players/puppy/define.h"

inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("spectacles");
   set_short("Grandpa Smurf's spectacles");
   set_long(
      "A pair of spectacles made especially for Grandpa Smurf.\n"+
      "Without them he wouldn't be able to see.\n");
   set_weight(1);
   set_value(50);
}

init()
{  add_action("wearr", "wear");   }

wearr(str)  {
   if(!str){ notify_fail("What are you trying to wear?\n"); return 0; }
   if (str == "glasses" || "spectacles") {
      write("You put on the spectacles.  They make you look so Smurfy.\n");
      say(this_player()->query_name()+" dons a Smurfy pair or spectacles.\n");
      return 1; }
}
