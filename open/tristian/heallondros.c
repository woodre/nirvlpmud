#include "/players/jareel/ansi.h";
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("energy");
  add_alias("aura");
  set_short(RED+"[ "+NORM+CYN+"Swirling Energy"+NORM+RED+" ]"+NORM);
  set_long("A electrically charged ball.\n"+
           "You feel that you can 'release'\n"+
           "its magical 'aura'.\n");
  set_type("auras");
  set_type_single("aura");
  set_msg("You mutter a few words.\n"+
          "You are surrounded by a "+RED+"Crimson "+NORM+"aura.\n");
  set_msg2(" is engulfed by a "+RED+"Crimson aura"+NORM+".\n");
  add_cmd("release");
set_msg_postcharges(NORM+RED+" ]"+NORM);
set_msg_precharges(RED+"[ "+CYN);
  set_heal(50,50);
  set_charges(3);
  set_soak(3);
  set_stuff(3);
  set_value(100);
}

query_save_flag(){
  return 1;
  }
