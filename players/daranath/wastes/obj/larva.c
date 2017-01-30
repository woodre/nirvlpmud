/* Can be purchased for 1050 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("centipede larva");
  add_alias("larva");
  add_alias("mass");
  set_short(CYN+"Queen Centipede Larval Mass"+NORM);
  set_long("A jelatinous mass that has several "+CYN+"centipede larva"+NORM+" wriggling\n"+
          "within. You think you can perhaps <"+HIR+"swallow"+NORM+"> one of them.\n");

  set_msg("You pluck one of the "+CYN+"wriggling larva"+NORM+" and swallow it down.\n");
  set_msg2(" plucks one of the "+CYN+"wriggling larva"+NORM+" and swallows it down.\n");
  add_cmd("swallow");
  set_type("larva");

  set_heal(25,0);
  set_charges(10);
  set_stuff(6);
  set_value(100);
}

query_save_flag(){
  return 1;
  }
