#include <ansi.h> /* 2007-10-29 removed ; after #include -Vital */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("beer");
  add_alias("house");
  add_alias("special");
  set_short(HIY+"House Special"+NORM);
  set_long("Special of the House.\n");
  set_type("bottles");
  set_type_single("bottle");
  set_msg("A tingling sensation runs through your body.\n");
  set_msg2(" guzzles down a special!\n");
  add_cmd("drink");
  set_intox(7);
  set_heal(20,20);
  set_charges(1);
  set_value(150);
}

query_save_flag() { return 1; }
