inherit "/obj/monster";
#include <ansi.h>

reset(arg)
{
if(arg) return;
    ::reset(arg);
    if(arg) return;
set_name("frat boy");
set_alias("boy");
set_short("A frat boy");
set_long("He is loud and obnoxious, with beer stains on his shirt. \n");
set_level(50);
set_hp(275);
set_al(-50);
set_wc(17);
set_ac(4);
add_money(random(0)+420);
}
