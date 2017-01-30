#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("Phantom Aura");
set_short(BOLD+BLK+"Phantom Aura"+NORM);
set_alias("aura");
set_long("The aura of the Gloom Assassin, the phantom monster that takes over\n"+
         "the dead corpse of Gundar killers.\n");
set_type("misc");
set_ac(2);
set_weight(1);
set_value(2100);
}

query_save_flag() {return 1;}

