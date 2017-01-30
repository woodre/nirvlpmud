inherit "/obj/monster";
#include <ansi.h>

reset(arg)
{
if(arg) return;
    ::reset(arg);
    if(arg) return;
set_name("chick");
set_alias("girl");
set_short("A half-naked hippy chick");
 set_long("This chick's eyes are all squinty and her body is half exposed.\n");
set_level(50);
set_hp(275);
set_al(-50);
set_wc(17);
set_ac(4);
add_money(random(50)+420);
}
