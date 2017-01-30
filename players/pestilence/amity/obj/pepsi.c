inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(""+HIR+"Pe"+HIW+"ps"+HIB+"i"+NORM+"");
  add_alias("pepsi");
  add_alias("soda");
  add_alias("pop");
  set_short(""+HIR+"Pe"+HIW+"ps"+HIB+"i"+NORM+"");
  set_long("This is a 20 oz. "+HIR+"Pe"+HIW+"ps"+HIB+"i"+NORM+" that has been chilled for\n"+
           "maximum refreshment.\n");    
  set_type("sips");
  set_msg("You take a large swig out of "+HIR+"Pe"+HIW+"ps"+HIB+"i"+NORM+", leaving you refreshed.\n");
  set_msg2(" takes a large swig out of the "+HIR+"Pe"+HIW+"ps"+HIB+"i"+NORM+", leaving them refreshed.\n");
  add_cmd("drink");
  add_cmd("sip");;
  set_heal(50,50);
  set_charges(3);
  set_soak(14);
  set_value(600);
}

query_save_flag(){
  return 1;
  }
