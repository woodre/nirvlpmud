#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("Silver cloak");
set_short(WHT+"Silver cloak"+NORM);
set_alias("cloak");
set_long("A cloak made from pure silver, its built to withstand the heat of this\n"+
         "area, and can probably take the heat in the bowels of the\n"+
         "earth itself.\n");
set_type("misc");
set_ac(1);
set_weight(1);
set_value(400 + random(200));
}
