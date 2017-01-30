inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if(arg) return;
    set_name("Oofa");
    set_race("oofa");
    set_ep(270000);
    set_alias("oofa");
    set_short("Oofa");
    set_long("What is Oofa? You don't know. There are lots of things out there\n"+
    "that simply cannot be explained.\n");
    set_level(13);
    set_hp(240);
    set_al(0);
    set_wc(17);
    set_ac(10);
    set_chance(40);
    set_spell_dam(10);
    set_spell_mess1("Oofa boggles at you.");
    set_spell_mess2("Oofa makes an odd noise.");
    set_chat_chance(10);
    load_chat("Oofa grinds itself.\n");
    load_chat("Oofa passes through your body.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(200)+700);
    move_object(gold,this_object());
    what=clone_object("players/mizan/etheriel/items/spuckpistol.c");
    move_object(what, this_object());
    move_object(clone_object("players/mizan/etheriel/items/spuckballs"), what);
    move_object(clone_object("players/mizan/etheriel/items/spuckballs"), this_object());
}
