/*  60tox/150 heal = .4  wich = cost 8 per heal 8*150= 1200 */
inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(""+HIB+"blueberry pie"+NORM+"");
  add_alias("blueberry pie");
  add_alias("blueberry");
  add_alias("berry");
  add_alias("pie");
  add_alias("berry pie");
  set_short(""+HIB+"a blueberry pie"+NORM+"");
  set_long("This is a "+HIB+"blueberry pie"+NORM+".\n"+
           "It looks like it would taste extremely good.\n");    
  set_type("bites");
  set_msg("You take a big bite of the "+HIB+"blueberry pie"+NORM+".\n");
  set_msg2(" takes a big bite of the "+HIB+"blueberry pie"+NORM+".\n");
  add_cmd("bite");
  add_cmd("eat");
  set_heal(50,50);
  set_charges(3);
  set_stuff(10);
  set_soak(10);
  set_value(400);
}
query_save_flag(){
  return 1;
  }
