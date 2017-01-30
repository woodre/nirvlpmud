inherit "/obj/armor";
#include <ansi.h>
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("shield");
  set_short(""+BOLD+"Shield of Justice"+NORM+"");
  set_long("A red and blue shield, with a star in the middle. The calling card of the\n"+
           "famed Captain America.\n");
  
  set_params("other|evil",0,25,0);
  set_ac(2);
  
  set_type("shield");
  set_weight(2);
  set_value(3000);
}
