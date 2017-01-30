#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("armor");
   set_alias("robe");
   set_short(HIK+"Night Goblin Robe"+NORM);
   set_long("This is the standard garb for the countless\n\
numbers of night goblins that lurk underground\n\
and in many other dark places.\n");
   
   set_ac(2);
   set_type("armor");  
   set_weight(1);
   set_value(150);
}
