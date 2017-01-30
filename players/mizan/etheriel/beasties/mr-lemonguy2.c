inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/Tracking-D.c"

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if(arg) return;
    set_name("Mr. Lemon Guy");
    set_race("guy");
    set_alias("lemon");
    set_short("Mr. Lemon Guy");
    set_long("This fool is clad in bright yellow and green tights. He looks and\n"+
    "acts like a total idiot. Would you trust this guy with your children?\n"+
    "I think not.\n");
    set_level(14);
    set_hp(210);
    set_al(10);
    set_wc(18);
    set_ac(11);
    set_chance(15);
    set_spell_dam(24);
    set_spell_mess1("Mr. Lemon Guy cries: Stop, foul evildoer!");
    set_spell_mess2("Mr. Lemon Guy goes: Aha! I shall doom you, evil villain!");
    set_chat_chance(10);
    load_chat("Mr. Lemon Guy thunders: Leave the dishes to ME!\n");
    load_chat("Mr. Lemon Guy goes: Everything... is under control!\n");
    load_chat("Mr. Lemon Guy laughs heartily.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+100);
    move_object(gold,this_object());
    gold=clone_object("/players/mizan/etheriel/items/spuckrifle");
    move_object(gold,this_object());
    move_object(clone_object("players/mizan/etheriel/items/spuckballs"), gold);
}
