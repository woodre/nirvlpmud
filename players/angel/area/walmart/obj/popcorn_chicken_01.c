#include <ansi.h> /* 2007-10-29 removed ; after #include -Vital */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("popcorn chicken");
  add_alias("corn");
  add_alias("chicken");
  add_alias("popcorn");
  set_short(HIR+"["+HIG+"Popcorn Chicken"+HIR+"]"+NORM);
  set_long("This is a cup of popcorn chicken. There is a doom shape lid on\n\
top of the cup with a circular hole cut out on top of the lid.\n\
You see steam coming out from the lid. You get a sudden urge to\n\
'pop' some of the corn into your mouth.\n");
  set_type("chicken chunks");
  set_type_single("chicken chunk");
  set_msg("As you turn over the cup to pour out some of\n\
the chicken your hand feels the hot steam!\n");
  set_msg2(" bites down on some chicken and the juices begin to ooze out!\n");
  add_cmd("pop");
  set_heal(40,40);
  set_charges(3);
  set_soak(7);
  set_stuff(7);
  set_value(320);
}

query_save_flag() { return 1; }
