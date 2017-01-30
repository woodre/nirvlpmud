#include "../std.h"

get()
{
   return 0;
}

id(str)
{
   return str == "shop" || str == "halloween shop" || str == "signs";
}

long(str)
{
   if(str == "signs")
      write("\tCOSTUMES INSIDE!\n"+
      "\t\tCHEESY HALLOWEEN GEAR!\n"+
      "\tAND MUCH MORE!\n"+
      "\t\t"+BOLD+"C H E A P ! ! ! !"+NORM+"\n");
   else write("A dirty little building with a few signs in the windows.\n"+
         "You can see some Halloween items inside, and there is a\n"+
      "big glass door you can <"+BOLD+"enter"+NORM+"> through.\n");
}

short()
{
   return "Verte's "+HIR+"Hal"+BOLD+BLK+"lowe"+HIR+"en"+NORM+" Shop";
}

init()
{
   add_action("cmd_enter","enter");
   add_action("cmd_in","in");
}

cmd_enter()
{
   write("You enter the Halloween shop...\n");
   TP->move_player("into the Halloween shop#"+PATH+"ROOMS/shop");
   return 1;
}

cmd_in()
{
   command("enter shop",TP);
   return 1;
}
