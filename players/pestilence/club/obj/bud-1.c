inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(""+RED+"bud"+WHT+"wei"+BLU+"ser"+NORM+"");
  add_alias("beer");
  add_alias("bottle of beer");
  add_alias("bud");
  add_alias("bottle");
  set_short("A bottle of "+RED+"Bud"+WHT+"wei"+BLU+"ser"+NORM+"");
  set_long("This is a bottle of pure Budweiser.  It's a 12 ounce size\n"+
           "This would taste real good to drink.\n");    
  set_type("sips");
  set_msg("You swig some "+RED+"Bud"+WHT+"wei"+BLU+"ser"+NORM+" down.\n");
  set_msg2(" drinks some "+RED+"Bud"+WHT+"wei"+BLU+"ser"+NORM+".\n");
  add_cmd("drink");
  add_cmd("swig");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(1);
  set_intox(20);
  set_value(600);
}
