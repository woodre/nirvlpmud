#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("mirror");
   set_short("A mirror");
   set_long(
      "A small hand-held mirror.  Vanity Smurf loves\n"+
      "to sit back and gaze into it all day long.\n");
   set_weight(1);
   set_value(50);
}

init()
{  add_action("mirror", "gaze");   }
mirror(str) {
   if(!str){ notify_fail("gaze what?\n"); return 0; }
   if(str == "mirror") {
      write("You gaze into the mirror.\n");
      say(this_player()->query_name()+"gazes into the mirror.\n");
      
      return 1;   }
   notify_fail("gaze what?\n"); return 0; }
