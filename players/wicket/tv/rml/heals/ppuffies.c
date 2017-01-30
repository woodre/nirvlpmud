#include "/sys/lib.h"
#include <ansi.h>

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("puffies");
  add_alias("pasture puffies");
  set_short("A bag of "+CYN+"Pa"+HIY+"st"+YEL+"ur"+RED+"e P"+YEL+"uf"+HIY+"fi"+CYN+"es"+NORM+"");
  set_long("A bag of pasture puffies. Go ahead take a EAT some.\n");
  set_type("eat");
  set_msg("You stuff a handful of puffies in your mouth. What A HEFFER!!!\n");
  set_msg2(" stuffs a handful of puffies in their mouth. What a HEFFER!!!\n");
  add_cmd("eat");
  set_heal(10,10); /* hp,sp */
  set_charges(10);
  set_stuff(14);
  set_value(10); /* This is per charge */
}
