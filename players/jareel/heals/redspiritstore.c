/************************************************
*             Jareel 1/9/2004
*          This is a heal Based 
*          current player trends
*           This is an sps heal
*    Heal is found in a PK no tp area
*********************************************** */

#include <ansi.h>
inherit "/obj/generic_heal.c";

  void reset(int arg) {
    ::reset(arg);
  if(arg) return;
  set_name("spirit");
  add_alias("aura");
  set_short(RED+"[ "+NORM+RED+"Swirling Energy"+NORM+RED+" ]"+NORM);
  set_long(
    "A spiritually charged ball of energy.  You\n"+
    "think that you can 'free' the energy from\n"+
    "the 'spirit' bound inside the ball.\n");
  set_type("spirit");
  set_type_single("spirit");
  set_msg("You mutter a few words.\n"+
    "You are surrounded by a "+RED+"Red "+NORM+"spirit aura.\n");
  set_msg2(" is engulfed by a "+RED+"Red "+NORM+"spirit aura"+NORM+".\n");
  add_cmd("free");
  set_msg_postcharges(NORM+RED+" ]"+NORM);
  set_msg_precharges(RED+"[ "+CYN);
  set_heal(0,100);
  set_charges(3);
  set_soak(6);
  set_stuff(6);
  set_value(100);
  }
status id(string arg) {
  return ( ::id(arg) || arg == "reds" || arg == "red" || arg == "energy" || arg == "swirling energy"); }

  query_save_flag(){
  return 1;
  }
