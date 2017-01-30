#include <ansi.h> /* 2007-10-29 removed ; after #include -Vital */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("beer");
  set_short(HIC+"First Class Beer"+NORM);
  set_long("A First Class Beer.\n");
  set_type("bottles");
  set_type_single("bottle");
  set_msg(" That feels good!\n");
  set_msg2(" chugs a beer.\n");
  add_cmd("drink");
  set_intox(3);
  set_heal(5,5);
  set_charges(1);
  set_value(25);
}

query_save_flag() { return 1; }
