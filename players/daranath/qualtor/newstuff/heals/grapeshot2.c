/* Can be purchased for 800 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("grapeshot");
  add_alias("grape");
  set_short(MAG+"Grapeshot"+NORM);
  set_long("A favorite amongst low level chars and those short on coins,\n"+
           "the "+MAG+"grapeshot"+NORM+" gives one a suitable sorce of healing.\n");

  set_msg("You take a bite of the "+MAG+"grapeshot"+NORM+"\n");
  set_msg2(" takes a bite of the "+MAG+"grapeshot"+NORM+"\n");
  add_cmd("eat");
  set_type("bite");

  set_heal(30,0);
  set_charges(3);
  set_stuff(9);
  set_value(50);
}

query_save_flag(){
  return 1;
  }
