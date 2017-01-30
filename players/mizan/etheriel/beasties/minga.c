inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if(arg) return;
    set_name("minga");
    set_race("minga");
    set_alias("minga");
    /*
    set_ep(39000);
    */
    set_short("Minga");
    set_long("What is a Minga? You're not all that sure. All that can be said\n"+
    "is that its not as big as the other 'things' floating around in here...\n");
    set_level(8);
    set_hp(135);
    set_al(0);
    set_wc(12);
    set_ac(6);
    set_chance(40);
    set_spell_dam(8);
    set_spell_mess1("Minga makes all sorts of grinding noises...");
    set_spell_mess2("Minga floats through your head.");
    set_chat_chance(10);
    load_chat("Minga floats though your head.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+200);
    move_object(gold,this_object());
    what=clone_object("players/mizan/etheriel/items/spuckballs.c");
    move_object(what, this_object());
    move_object(clone_object("players/mizan/etheriel/items/util-belt.c"), this_object());
}
