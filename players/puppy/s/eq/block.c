#define tp this_player()->query_name()
#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("block");
   set_short("A building block");
   set_long(
      "A small building block with letters on each of its\n"+
      "sides.   Baby Smurf likes to 'play_with' his blocks.\n");
   set_weight(1);
   set_value(20);
}

init()
{  add_action("block", "play_with");   }
block(str)  {
   if(!str){ notify_fail("play_with what?\n"); return 0; }
   if(str == "block")  {
      
      write("You flip over the block and watch it tumble away.\n");
      say(tp+" flips the block over and it tumbles away.\n");
      destruct(this_object());
      return 1;   }
   notify_fail("play_with what?\n"); return 0; }
