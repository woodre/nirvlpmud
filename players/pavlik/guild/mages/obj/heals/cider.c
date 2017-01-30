inherit "/obj/generic_heal";

#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Jug of Apple Cider");
  add_alias("jug");
  add_alias("jug of apple cider");
  add_alias("cider");
  add_alias("apple cider");
  set_short("A Jug of Apple Cider");
  set_long("A jug of sweet apple cider.\n");
  set_type("swigs");
  set_type_single("swig");
  set_msg("You uncork the jug and take a swig of the cider.\n"+
          "It's a sweet juice with a little bit of a kick.\n");
  set_msg2(" takes a swig of cider.\n");
  set_empty_msg("You crumple up the jug and recycle it (how nice).\n");
  add_cmd("drink");
  add_cmd("swig");
  add_cmd("chug");
  add_cmd("gulp");
  add_cmd("quaff");
  set_heal(25,75);
  set_charges(3);
  set_intox(20);
  set_value(250);
  /* see apple pie for heal guidelines */
}