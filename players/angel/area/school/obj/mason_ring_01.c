#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("mason ring");
  set_alias("ring");
  set_short(HIY+"Mason Ring"+NORM);
  set_long("\
A Square and Compass set in gold. Masonic jewelry\n\
is handcrafted and held to the highest standards\n\
of quality\n");
  set_ac(2);
  set_type("ring");   
  set_weight(2);      
  set_value(2000);        
}