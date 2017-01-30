#include <ansi.h> /*  Why do people still use their own ansi headers? -Vital  */
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("stone");
 alias = ({"hell stone"});
  set_short(BOLD+"["+YEL+"Hell Stone"+NORM+BOLD+"]"+NORM);
  set_long("A small yellow stone, you feel like you can 'focus' its 'stone'.\n");
  set_type("focuses");
  set_type_single("focus");
set_msg_precharges(HIW+"["+YEL);
set_msg_postcharges(NORM+HIW+"]"+NORM);
  set_msg("You mutter a few words.\n"+
          "A black aura washes over you, you feel sick.\n");
  set_msg2(" is washed by a black aura.\n");
  add_cmd("focus");
  set_heal(-50,-50);
  set_charges(3);
  set_soak(-50);
  set_stuff(-50);
  set_value(0);
}

query_save_flag(){
  return 1;
  }
