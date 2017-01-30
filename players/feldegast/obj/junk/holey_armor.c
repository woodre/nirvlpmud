#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("armor");
  set_type("armor");
  set_ac(1);
  set_short(RED+"Holey Armor"+NORM);
  set_long(
"You imagine this magnificient piece of armor was once worn by some noble\n"+
"lord or king...Who then got a new suit of armor and gave this suit to some\n"+
"disfavored relative who promptly stored it in the attic for a decade or two\n"+
"before noticing the hole in the roof which slowly eroded huge rust holes\n"+
"in strategic places.\n");
  set_weight(4);
  set_value(5);
}
int do_special(object owner)
{
  if(!random(12))
  {
    tell_object(owner,(string)this_player()->query_name()+" hits you through a gaping hole in your armor.\n");
    owner->hit_player(random(20));
    return 0;
  }
}
