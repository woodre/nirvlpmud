#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("parchment");
   set_short("Parchment");
   set_long(
      "A fairly large piece of paper used for writing thoughts\n"+
      "on.  It is rolled up and tied with a piece of string.\n");
   set_weight(1);
   set_value(75);
}

init()
{  add_action("paper", "untie");   }
paper(str) {
   if(!str){ notify_fail("What are you trying to untie?\n"); return 0; }
   if(str == "parchment" || str == "string")  {
      write("You untie the parchment but a stong force prevents you from reading it.\n");
      say(this_player()->query_name()+ " unties the parchment and concentrates on the writing.\n");
      return 1;   }
}
