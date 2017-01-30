#include <ansi.h> /* 2007-10-29 removed ; after #include -Vital */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Kahlua ");
  add_alias("kahlua");
  add_alias("bottle");
  add_alias("drink");
  add_alias("coffee");
  add_alias("liquor");
  add_alias("cap");
  set_short(HIB+"["+MAG+"Kahlua"+HIB+"]"+NORM);
  set_long("This is a four pack of Kahlua. This is a rich,\n\
dark brown coffee liqueur made from the finest Mexican coffee,\n\
with fine cane spirits and a hint of vanilla. It also contains\n\
sugar, corn syrup and vodka, and has a thicker body than most\n\
other alcoholic beverage (70 Proof). You notice you will have\n\
to 'twist' the cap off if you wish to enjoy the rich flavor!\n");
  set_type("bottles");
  set_type_single("bottle");
  set_msg("As you put the bottle neck up to your\n\
mouth you can smell the wonderful aroma!\n");
  set_msg2(" feels refreshed as the exotic flavor flows smoothly down!\n");
  add_cmd("twist");
  set_intox(5);
  set_heal(50,50);
  set_charges(4);
  set_value(1000);
}

query_save_flag() { return 1; }
