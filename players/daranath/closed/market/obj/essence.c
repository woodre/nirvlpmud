/* Market Value of 1408 coins, available at the Bone Shop for 
   1200 coins AND 750 credits */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("unholy essence");
  add_alias("essence");
  add_alias("unholy essence");
  set_short(HIR+"Essence of the Fallen"+NORM);
  set_long("Gathered up over time, the "+HIR+"Essence of the Fallen"+NORM+" can help\n"+
           "sustain one over a period of time. You believe that you\n"+
           "can "+HIW+"<"+RED+"absorb"+HIW+">"+NORM+" some of the essence.\n");

  set_msg("You draw some of the "+HIR+"Essence of the Fallen"+NORM+" into your soul.\n");
  set_msg2(" absorbs some of the "+HIR+"Essence of the Fallen"+NORM+".\n");
  add_cmd("absorb");
  set_type("absorption");

  set_heal(0,50+random(25));
  set_charges(4);
  set_stuff(5);
  set_soak(5);
  set_value(450);
}

query_save_flag(){
  return 1;
  }
