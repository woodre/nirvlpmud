#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

inherit "obj/armor";
reset(arg){
   ::reset(arg);

  set_name("pink fuzzy handcuffs");
  set_short("A pair of "+HIM+"pink fuzzy"+NORM+" handcuffs");
  set_alias("handcuffs");
set_long("A pair of pink, fuzzy handcuffs. Perfect for strapping down your\n"+
         "lover and having your way with her. Prefered by women everywhere.\n"+
         "\n-Another fabulous Daranath product\n");
  set_type("ring");
  set_ac(1);
  set_weight(1);
  set_value(100);
}

