#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("helm");
  set_short(BOLD+BLK+"Infamous Helm"+NORM);
  set_long("This is the legendary...well..."+BOLD+"infamous"+NORM+" helm worn by Sir Arthur Valiant\n"+
           "the Short-Lived at the Battle of Brothelmeyer.  It is said his opponent's\n"+
           "sword went through this piece of armor 'like tissue'.\n");
  set_weight(1);
  set_value(5);
  set_type("helmet");
  set_ac(1);
}
int do_special(object owner)
{
  if(!random(20))
  {
    tell_object(owner,"Quite by chance, your opponent gets a lucky blow to your head.\n");
    owner->hit_player(random(20));
    return 0;
  }
}
