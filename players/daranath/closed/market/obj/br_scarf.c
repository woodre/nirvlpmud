#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("scarf");
set_short("Qual'tor breathing Scarf");
set_alias("br_scarf");
set_long("A large thick scarf that can be worn over the mouth and nose,\n"+
         "the scarves were created to protect against Qual'tors Ash.\n");
type = "scarf";
set_ac(1);
set_weight(1);
set_value(75);
}

query_save_flag() {return 1; }
