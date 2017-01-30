#include <ansi.h> /* 2007-10-29 removed ; after #include -Vital */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("capri sun");
  add_alias("capri");
  add_alias("sun");
  add_alias("capri sun");
  add_alias("juice");
  add_alias("pouch");
  set_short(HIR+"["+HIW+"Capri Sun"+HIR+"]"+NORM);
  set_long("A foil pouch filled with mixed fruit juice blends. This is 100%\n\
fruit juice. There is a straw attached to the back of the pouch.\n");
  set_type("sips");
  set_type_single("sip");
  set_msg("The flavor flowing over your taste buds\n\
as you sip it makes you eyes squinch!\n");
  set_msg2(" sucks on the straw as it flows smoothly down.\n");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(4);
  set_soak(6);
  set_stuff(6);
  set_value(700);
}

query_save_flag() { return 1; }
