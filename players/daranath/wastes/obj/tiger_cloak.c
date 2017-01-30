#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("Tiger cloak");
set_short("Cloak of the "+YEL+"Tiger"+NORM);
set_alias("cloak");
set_long("A soft, encompasing cloak, the Tiger Cloak looks like it was made from\n"+
         "the fur of the great cat itself. Perfectly preserved, this might \n"+
         "fetch a good number of coins at the right shop.\n");
set_type("misc");
set_ac(2);
set_weight(1);
set_value(200 + random(200));
}
