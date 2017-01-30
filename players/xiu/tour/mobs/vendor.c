inherit "/obj/monster";
#include <ansi.h>

reset(arg)
{
if(arg) return;
    ::reset(arg);
    if(arg) return;
set_name("vendor");
set_alias("guy");
set_short("A shady looking vendor.");
set_long("A middle-aged balding fellow who wears his hair as a skullet.\n"+
"He wears a baby blue mesh bag on his back, carrying who knows what\n"+
"His eyes shift around, watching everyone. \n");
set_level(50);
set_hp(275);
set_al(-50);
set_wc(17);
set_ac(4);
    set_chat_chance(10);
load_chat("A man in a jogging suit mumbles something inaudible to you.\n");
add_money(random(0)+420);
}
