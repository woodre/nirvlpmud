/* Can be purchased for 1800 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("ooze");
  add_alias("vial");
  set_short("A "+HIW+"vial"+NORM+" of "+MAG+"Gelatinous Ooze"+NORM);
  set_long("A vial that was purchased with a thick ooze residing inside.\n"+
           "You can "+HIW+"suck"+NORM+" the ooze for a healing effect.\n");

  set_msg("You suck the strange "+MAG+"ooze"+NORM+" down. It slides down your\n"+
          "throat and warms your body, healing your wounds.\n");
  set_msg2(" quaffs a strange "+MAG+"ooze"+NORM+" from a small vial.\n");
  add_cmd("suck");
  set_type("portion");

  set_heal(50,50);
  set_charges(3);
  set_soak(7);
  set_stuff(7);
  set_value(200);
}

query_save_flag(){
  return 1;
  }
