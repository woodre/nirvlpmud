inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold, bag, cloak;
    ::reset(arg);
    if(arg) return;
    set_name("box");
    set_race("box");
    set_alias("carton");
    set_short("A UPS shipping box");
    set_long("  This is an ordinary looking UPS carton. Ordinary color, ordinary size,\n"+
    "  except most ordinary boxes don't bite at your toes!\n");
    set_level(9);
    set_hp(150);
    set_al(-1000);
    set_wc(13);
    set_ac(4);
    set_chance(20);
    set_spell_dam(10);
    set_spell_mess1("A UPS carton falls on your foot!");
    set_spell_mess2("A UPS carton exclaims: Hey! You meanie!");
    set_chat_chance(5);
    load_chat("A UPS carton grumbles at you.\n");
    bag=clone_object("players/mizan/etheriel/items/ziploc.c");
    move_object(bag, this_object());
    cloak=clone_object("players/mizan/etheriel/items/spuckhelm.c");
    move_object(cloak, this_object());
    gold=clone_object("obj/money");
    gold->set_money(random(600)+150);
    move_object(gold,this_object());
}
