/* Market Value of 2100 coins, available at the Bone Shop for 
   1700 coins AND 1250 credits */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("piece of flesh");
  add_alias("flesh");
  add_alias("piece");
  set_short(YEL+"Piece of Flesh"+NORM);
  set_long("A small peice of flesh, it has been preserved perfectly for storage.\n"+
           "If you feel up to it, you may <"+HIR+"eat"+NORM+"> the flesh.\n");

  set_msg("You take a bite from the "+YEL+"Piece of Flesh"+NORM+".\n");
  set_msg2(" takes a bite of something hidden in thier hand.\n");
  add_cmd("eat");
  set_type("bite");

  set_heal(50,50);
  set_charges(3);
  set_stuff(12);
  set_value(700);
}

query_save_flag(){
  return 1;
  }
