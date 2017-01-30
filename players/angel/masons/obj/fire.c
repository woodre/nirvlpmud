#include <ansi.h> /* 2007-10-29 removed ; after #include -Vital */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("beer");
  add_alias("fire");
  add_alias("breather");
  set_short(HIR+"Fire"+HIW+"breather"+NORM);
  set_long("A First Class Beer.\n");
  set_type("bottles");
  set_type_single("bottle");
  set_msg(" A shock wave runs through your body.\n");
  set_msg2(" guns down a firebreather.\n");
  add_cmd("drink");
  set_intox(13);
  set_heal(30,30);
  set_charges(1);
  set_value(250);
}

query_save_flag() { return 1; }
