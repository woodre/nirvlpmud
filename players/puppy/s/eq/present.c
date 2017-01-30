#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("present");
   set_alias("box");
   set_short("A Present");
   set_long(
      "A box with a large bow on top.  Jokey Smurf likes to give\n"+
      "these out to people that he comes in contact with.  Is it\n"+
      "a present or a joke?  One only has to open it to find out.\n");
   set_weight(1);
   set_value(50);
}

init()
{  add_action("open_me", "open");   }

open_me(str)  {
   if(!str){ notify_fail("open what?\n"); return 0; }
   if (str == "present" || str == "box") {
      
      write("You open the present and it explodes in your face.\n");
      say(this_player()->query_name()+" opens the present and it explodes.\n");
      this_player()->hit_player(5, "other|puppy");
      destruct(this_object());
      
      return 1;   }
   notify_fail("open what?\n"); return 0; }
