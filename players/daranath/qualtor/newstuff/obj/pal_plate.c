#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("paladin platemail");
set_short("Holy plate armor");
set_alias("platemail");
set_long("Forged in the dwarven furances within Qual'tor, this armor is then\n"+
         "taken to the temples and blessed for the Paladins of the city.\n");
set_type("armor");
set_ac(3);
set_weight(2);
set_value(2275);
}
