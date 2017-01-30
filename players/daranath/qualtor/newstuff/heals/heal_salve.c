/* Can be purchased for 1200 coins from Randal at the market square or
    at the East Road shop in qualtor */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("salve");
  add_alias("tin");
  set_short("A tin of healing "+WHT+"salve"+NORM);
  set_long("A tin of healing salve. You can "+WHT+"apply"+NORM+" the salve.\n");

  set_msg("You apply the "+WHT+"healing salve"+NORM+" to your wounds.\n");
  set_msg2(" applies the salve to thier wounds.\n");
  add_cmd("apply");
  set_type("application");

  set_heal(25,25);
  set_charges(6);
  set_soak(12);
  set_value(100);
}

query_save_flag(){
  return 1;
  }
