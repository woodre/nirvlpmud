#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("Skull Helm");
set_short(WHT+"Skull Helm"+NORM);
set_alias("helm");
set_long("A large human skull, one that has been cleaned and strengthened so\n"+
         "it can be worn as a helmet. Rather ugly to look at, but effective\n"+
         "during a fight.\n");
set_type("helmet");
set_ac(2);
set_weight(1);
set_value(2500+random(300));
}

query_save_flag() {return 1; }
