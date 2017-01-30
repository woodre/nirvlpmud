#include <ansi.h> /* 2007-10-29 removed ; after #include -Vital */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("chunk cheese");
  add_alias("cheese");
  add_alias("chunk");
  set_short(HIR+"["+HIY+"Chunk Cheese"+HIR+"]"+NORM);
  set_long("This is a large block of medium cheddar cheese. It is\n\
produced for Wal-Mart Stores Inc. If you would like\n\
to eat a chunk try to 'slice' it!\n");
  set_type("chunks");
  set_type_single("chunk");
  set_msg("The large block of medium cheddar cheese\n\
is putting out a desirable aroma!\n");
  set_msg2(" slices the block of cheese as your mouth begins to water.\n");
  add_cmd("slice");
  set_heal(50,50);
  set_charges(4);
  set_soak(3);
  set_stuff(3);
  set_value(1100);
}

query_save_flag() { return 1; }
