#define tp this_player()->query_name()
#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("cake");
set_alias ("birthday cake");
set_short("Shinishi's Birthday Cake");
   set_long("A BIRTHDAY CAKE made just for you.  You may 'blow candles'.\n");
   set_weight(0);
   set_value(0);
}

init()
{  add_action("candles", "blow");   }
candles(str)  {
if(str == "candles")  {
write("You try to blow out the candles but find someone\n"+
"has put trick candles on the cake,they will not go out.\n"+
"\t\t HAPPY BIRTHDAY!!!!!\n");
say(tp+" shows you a BIRTHDAY CAKE!!!!");
      return 1;   }
}
