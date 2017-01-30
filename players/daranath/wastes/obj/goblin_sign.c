#include <ansi.h>
#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;

   set_id("sign");
   set_alias("goblin sign");
   set_short("A "+HIG+"goblin warning sign"+NORM+" ");
   set_long("A wooden sign, written by goblins.\n"+
           "You can "+HIY+"read"+NORM+" the "+HIY+"sign"+NORM+".\n");
   set_weight(1);
   set_value(1);
}

init()  {
  ::init();
  add_action("read_sign","read");
        }

read_sign(str)  {
  if(str == "sign")  {
write("The goblin sign reads:\n"+
      "\n     Humanz...   Keep Out!\n\n"+
      "                   -Cormax\n");
return 1;
        }
  write("What do you want to read?\n");
return 1;
        }

get()  { return 0; }
