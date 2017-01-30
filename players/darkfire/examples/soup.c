inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("soup");
  add_alias("thermos");
  add_alias("thermos of soup");
  add_alias("food");
  add_alias("shake");
  set_short("Thermos of "+YEL+"Soup"+NORM+"");
  set_long("A thermos of steaming hot soup, just what the doctor ordered.\n");    
  set_type("drink");
  set_msg("You take a drink of the "+YEL+"Soup"+NORM+".\n");
  set_msg2(" takes a drink of the "+YEL+"Soup"+NORM+".\n");
  add_cmd("drink");
  add_cmd("gulp");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_stuff(6);
  set_soak(6);
  set_value(700);
}

query_save_flag() { return 1; }