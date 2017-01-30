#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("pipe");
   set_short("Longpipe");
   set_long(
   "A blackened stone bowl with a long straight stem of hollow reed.\n"+
   "The pipe is full of tabac. If you are over eighteen, you could\n"+
   "try to 'smoke' the pipe. \n");
   set_weight(1);
   set_value(60);
}

init()
{  add_action("smoke_pipe", "smoke");   }


smoke_pipe(str)  {

if(str == "pipe")  {

  write("You take a deep puff from the pipe.\n\n "+WHITE+"**You see odd shapes in the clouds.**"+OFF+"\n");
       
  say(tp+" takes a deep puff from the pipe and\n\n "+WHITE+"**he fancies odd shapes in the clouds.**"+OFF+"\n");

    return 1;   }
        }