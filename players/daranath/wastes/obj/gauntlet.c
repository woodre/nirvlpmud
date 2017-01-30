#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("defensive gauntlet");
set_short("Gauntlet of "+WHT+"Defense"+NORM);
set_alias("gauntlet");
set_long("An ornate, mithril gauntlet, the Gauntlet of Defense has a large onyx\n"+
     "embedded within the back of the hand.\n");
set_type("ring");
set_ac(2);
set_weight(1);
set_value(2250);
}

query_save_flag() { return 1; }
