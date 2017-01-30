inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/Tracking-D.c"
#include "/players/mizan/closed/NewbieGuard.c"

reset(arg)
{
    object gold;
    ::reset(arg);
    if(arg) return;
    set_name("something");
    set_race("something");
    set_alias("something");
    set_short("Something");
    set_long("Yep. This is definitely Something all right!\n");
    set_level(15);
    set_hp(300);
    set_al(0);
    set_wc(18);
    set_ac(8);
    set_chat_chance(10);
    load_chat("Something moves.\n");
    load_chat("Something does something.\n");
    load_chat("Something licks you.\n");
    load_chat("Something boggles at you.\n");
    gold=clone_object("obj/money");
    gold->set_money(1200);
    move_object(gold,this_object());
}
