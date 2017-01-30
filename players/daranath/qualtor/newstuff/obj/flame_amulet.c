#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("flame amulet");
set_short("Amulet of "+HIR+"Flame"+NORM);
set_alias("flame");
set_long("A small bright red amulet, the "+HIR+"Flame"+NORM+" Amulet was used to\n"+
         "identify members of the Children of Flame.\n");
set_type("amulet");
set_ac(1);
set_weight(1);
set_value(200+random(200));
}
