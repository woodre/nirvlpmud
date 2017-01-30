#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("cake");
  add_alias("piece");
  set_short(BOLD+"A slice of white cake"+NORM+NORM);
  set_long("A large slice of Stardreams white cake.\n"+
           "You feel that you can 'eat' the cake.\n"+
           "\n");
  set_type("cake");
  set_type_single("slice");
  set_msg("You start to drool as you lift the slice to your mouth.\n"+
          "You are filled with the lead weightthat is this cake.\n");
  set_msg2(" is engorged by some great cake.\n");
  add_cmd("eat");
set_msg_postcharges(NORM+RED+" ]"+NORM);
set_msg_precharges(RED+"[ "+CYN);
  set_heal(0,0);
  set_charges(1);
  set_soak(0);
  set_stuff(100);
  set_value(100);
}

query_save_flag(){
  return 1;
  }
