inherit "/obj/generic_heal";

#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("bag of powdered donuts");
  add_alias("powdered donuts");
  add_alias("bag of donuts");
  add_alias("bag");
  add_alias("donuts");
  set_short("A bag of "+HIW+"powdered donuts"+NORM);
  set_long("A bag of Helen's wonderful white powdery donuts cookies.\n");
  set_type("cookies");
  set_type_single("cookie");
  set_msg("You gobble down a donut.\n"+
          "You get "+HIW+"white powder"+NORM+" all over your face.\n");
  set_msg2(" eats a donut, "+HIW+"white powder"+NORM+" flying everywhere.\n");
  set_empty_msg("The donuts are all gone.\n");
  add_cmd("bite");
  add_cmd("eat");
  set_heal(18,6);
  set_charges(12);
  set_stuff(5);
  set_value(60);
  /* see apple pie for heal guidelines */
}