#include "/players/jareel/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("energy");
  add_alias("sphere");
  set_short(RED+"[ "+NORM+CYN+"Swirling Lunar Energy"+NORM+RED+" ]"+NORM);
  set_long("A swirling ball or rolling lighting encased in a magical bluish sphere.\n"+
           "One could apply the power of the sphere to heal major wounds magically.\n"+
           "This is a very powerful bundle of magic.\n");
  set_type("sphere");
  set_type_single("energy");
  set_msg("You mutter a few words.\n"+
          "You are surrounded by a "+RED+"Crimson "+NORM+"aura.\n");
  set_msg2(" is engulfed by a "+RED+"Crimson aura"+NORM+".\n");
  add_cmd("apply");
set_msg_postcharges(NORM+RED+" ]"+NORM);
set_msg_precharges(RED+"[ "+CYN);
  set_heal(100,100);
  set_charges(3);
  set_soak(0);
  set_stuff(0);
  set_value(10000);
}

query_save_flag(){
  return 1;
  }
