#define tp this_player()->query_name()
#include "/players/martha/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("piccolo");
   set_short("A Peppermint Piccolo");
   set_long(
      "This small musical instrument plays beautiful\n"+
      "tunes when you 'blow' it.\n");
   set_weight(0);
   set_value(0);
}

init()
{  add_action("blow_piccolo", "blow");   }
blow_piccolo(str)  {
   if(str == "piccolo")  {
      
      write("You blow the piccolo.\n Toot tootie toot!\n");
      say(tp+" blows a piccolo.\n Toot tootie toot!\n");
      return 1;   }
   
}
