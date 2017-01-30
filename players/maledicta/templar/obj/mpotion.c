/* price 2400 */
#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("potion");
  set_short(BLU+"Potion of "+HIB+"Major Healing"+NORM);
  set_long("This is a small vial of healing liquid. You\n"+
           "can 'imbibe' it in order to benefit from its\n"+
           "effects.\n");
  set_type("drink");
  set_msg("You quickly pop the cork from the potion and imbibe it.\n");
  set_msg2(" drinks a potion.\n");
  add_cmd("imbibe");
  set_heal(50,50);
  set_charges(3);
  set_soak(5);
  set_stuff(5);
  set_value(800);
}

query_save_flag(){
  return 1;
  }
