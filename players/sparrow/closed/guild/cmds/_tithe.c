#include <ansi.h>
cmd_tithe(str)
{
  int x;
  if(!str || str == "0") {
      write("You must specify an amount to tithe!\n");
      return 1;
  }
  x = atoi(str);
  if(x < 0) {
    write("Ok cheater, I'll convert that to a "+BOLD+"POSITIVE"+NORM+" number for you!\n");
    x = -x;
  }
  if(this_player()->query_money() < x) {
    write("You "+BOLD+"do not"+NORM+" have enough money to tithe "+HIY+x+NORM+" coins!\n");
    return 1;
  }
  this_player()->add_money(-x);
  previous_object()->addWorth(x);
  write("You have tithed "+HIK+"["+HIY+x+HIK+"]"+NORM+" gold coins...\n"+
    "\t\t...and your Parish is now worth "+HIK+"["+HIY+previous_object()->queryWorth()+HIK+"]"+NORM+" coins.\n");
  return 1;
}
