/* Can be purchased for 1800 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/cobain/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("ichor");
  add_alias("rancid ichor");
  set_short(BOLD+"Rancid Ichor"+NORM);
  set_long("A thick and extremly pungent slime, the ichor stored\n"+
           "within this small glass flask has definently gone rancid.\n"+
           "You can <"+YEL+"drink"+NORM+"> the ichor if you feel inclined.\n");

  set_msg("You grimace and drink down some "+YEL+"Rancid Ichor"+NORM+" from the small glass flask.\n");
  set_msg2(" drinks a thick, pungent "+YEL+"ichor"+NORM+" from a small flask.\n");
  add_cmd("drink");
  set_heal(50,50);
  set_charges(3);
  set_soak(5);
  set_stuff(5);
  set_value(375);

  /* With Cobain Extensions */
  set_type("drinks");
  set_type_single("drink");
  set_msg_precharges("<"+HIG);
  set_msg_postcharges(NORM+">");

}

query_save_flag(){
  return 1;
  }
