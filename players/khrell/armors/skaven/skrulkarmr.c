#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("battle_armor");
   set_alias("plate");
   set_short(YEL+"Skrulkt's battle armor"+NORM);
   set_long("\
   This was the armor formerly worn by Master Warlock Engineer\n\
Skrulkt.  It looks as if it is quite heavy, and will provide  \n\
anyone wearing it with alot of protection.\n");   
   set_ac(5);
   set_type("armor");
   set_weight(3);
   set_value(2000);
}
