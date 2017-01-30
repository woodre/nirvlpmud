inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/HighLevelGuard.c"

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if(arg) return;
    set_name("A sheep named 'Bleh'");
    set_race("sheep");
    set_alias("bleh");
    set_short("A sheep named 'Bleh'");
    set_long("This is a fuzzy white sheep covered with a thick layer of\n"+
    "purple goo. It absolutely refuses to shut up, and you REALLY want\n"+
    "to kill it.\n");
    set_level(5);
    set_hp(75);
    set_al(-11);
    set_wc(9);
    set_ac(5);
    set_chat_chance(10);
    load_chat("A sheep named 'Bleh' goes: Bleh. Bleh.\n");
    load_chat("A sheep named 'Bleh' blinks in disbelief.\n");
    load_chat("A sheep named 'Bleh' says: Bleh. Bleh.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(10)+50);
    move_object(gold,this_object());
    what=clone_object("players/mizan/etheriel/items/pocket-fuzz.c");
    move_object(what, this_object());
}
