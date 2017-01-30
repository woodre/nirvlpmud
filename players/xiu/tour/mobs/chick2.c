inherit "/obj/monster";
#include <ansi.h>

reset(arg)
{
if(arg) return;
    ::reset(arg);
    if(arg) return;
set_name("woman");
set_alias("girl");
set_short("A dreadlocked woman");
set_long("A woman with thick, frizzy dreads.\n");
 set_level(18);
set_hp(275);
set_al(5);
set_wc(17);
set_ac(4);
add_money(random(50)+420);
}
