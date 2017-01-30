inherit "/obj/treasure.c";
#include "/players/fred/ansi.h"

reset(arg){

  set_id("coin purse");
  set_alias("purse");
  set_long(
"  This is a small purse used to carry gold coins.  It is made of leather\n"+
"and has a small metal zipper on the top.  If you opened the purse then\n"+
"you could easily get the gold out of it.\n");
  set_weight(1);
}

short(){
  if(!value) 
    return "An empty coin purse";
  else 
    return "A purse containing "+value+HIY+" gold coins"+NORM;
}

void init(){
  ::init();
  add_action("open", "open");
}

status open(string str)
{
  int c,d;
  if(str != "purse") return 0;
  if(!present(this_object(), this_player())) return 0;
  if(((c = (int)this_player()->query_money()) + value) > 80000)
    d = (80000 - c);
  else
    d = value;
  if(d == 0)
    return (notify_fail("You already have 80000 gold coins.\n"), 0);
  this_player()->add_money(d);
  value -= d;
  write("You open the purse and take "+d+" gold coins from it.\n");
  if(!value)
    write("You toss away the empty coin purse.\n");
  else
    write("There are still "+value+" gold coins in it.\n");
  return 1;
}
