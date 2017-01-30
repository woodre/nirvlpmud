#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("pipe");
   set_short("A briar pipe");
   set_long(
   "A slender briar pipe with a long curved detachable stem.\n"+
   "It is full and lit. If you are over eighteen, you could\n"+
   "try to 'smoke' the pipe. \n");
   set_weight(1);
   set_value(75);
}

init()
{  add_action("smoke_pipe", "smoke");   }


smoke_pipe(str)  {

if(str == "pipe")  {

  write("You take a deep puff from the pipe.\n You feel "+WHITE+"**DIZZY**"+OFF+"\n");
       /* Note how tp is used */
  say(tp+" takes a deep puff from the pipe and\n he feels "+WHITE+"**DIZZY**"+OFF+"\n");

    return 1;   }
        }