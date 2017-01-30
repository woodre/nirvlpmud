#include "/players/jareel/ansi.h"
inherit "/obj/generic_heal.c";
inherit "/obj/weapon";

  void reset(int arg)
    {
    ::reset(arg);
      if(arg) return;
   set_name("vitality elixir");
   add_alias("elixir");
   set_short("A Vitality "+HBGRN+BLU+"Elixir"+NORM);
   set_long(
     "A bright yellow mixture of potions and healing herbs.\n"+
     "Drinkinging the Elixir will cure an advanturerd wounds.\n"+
     "This is a very concentrated formula.\n");
   set_type("drink");
   set_type_single("sip");
   set_msg(
     "You take a drink of the "+BYEL+BLU+"Elixir"+NORM+".\n");
   set_msg2(
     " takes a drink from the "+BYEL+BLU+"Elixir\n");
   add_cmd("drink");
   set_msg_postcharges(NORM+YEL+"]"+NORM);
   set_msg_precharges(NORM+YEL+"["+BOLD+CYN);
   set_heal(50,50);
   set_charges(100);
   set_soak(10);
   set_stuff(10);
   set_value(40000);
}

query_save_flag(){
  return 1;
  }
