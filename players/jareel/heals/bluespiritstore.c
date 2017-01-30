#include <ansi.h>
inherit "/obj/generic_heal.c";

  void reset(int arg) {
    ::reset(arg);
  if(arg) return;
  set_name("spirit");
  add_alias("blue");
  set_short(RED+"[ "+NORM+BLU+"Swirling Energy"+NORM+RED+" ]"+NORM);
  set_long(
    "A spiritually charged ball of energy.  You\n"+
    "think that you can 'free' the energy from\n"+
    "the 'spirit' bound inside the ball.\n");
  set_type("spirit");
  set_type_single("spirit");
  set_msg("You mutter a few words.\n"+
    "You are surrounded by a "+BLU+"Blue"+NORM+" spirit aura.\n");
  set_msg2(" is surrounded by a "+BLU+"Blue "+NORM+"spirit aura"+NORM+".\n");
  add_cmd("free");
  set_msg_postcharges(NORM+RED+" ]"+NORM);
  set_msg_precharges(RED+"[ "+BLU);
  set_heal(100,0);
  set_charges(3);
  set_soak(6);
  set_stuff(6);
  set_value(100);
}

status id(string arg) {
  return ( ::id(arg) || arg == "blues" || arg == "blue" || arg == "energy" || arg == "swirling energy"); }

query_save_flag(){
  return 1;
  }
