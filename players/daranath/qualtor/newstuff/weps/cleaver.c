#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Bloody Cleaver");
set_type("axe");
set_alias("cleaver");
set_short("Massive blood stained Cleaver");
set_long("A meat cleaver that stands an impressive 4 feet in length, this\n"+
         "weapon can only be used by the strongest individuals on Nirvana.\n"+
         "Not for the faint of heart....\n");
set_class(21);
set_weight(3);
set_value(4100+random(1000));
}

query_save_flag() {return 1; }
