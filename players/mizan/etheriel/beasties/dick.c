inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object bat, gold;
    ::reset(arg);
    if(arg) return;
    set_name("dick");
    set_race("fat guy");
    set_alias("fat guy");
    set_short("Dick the Wombat Beater");
    set_long("This is Dick the Wombat Beater. He likes to beat Wombats on the\n"+
    "head with his aluminum baseball bat.\n");
    set_level(6);
    set_hp(120);
    set_al(-1000);
    set_wc(9);
    set_ac(5);
    set_chance(20);
    set_spell_dam(7);
    set_spell_mess1("Dick screams: DIE! DIE! DIE! DIE! hehehe *grunt*");
    set_spell_mess2("Dick pounds you with is bat. *KLUNG!*");
    set_chat_chance(10);
    load_chat("Dick grins stupidly.\n");
    load_chat("Dick whomps a wombat on the head.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(20)+50);
    move_object(gold,this_object());
    bat=clone_object("players/mizan/etheriel/items/bat.c");
    move_object(bat, this_object());
}
