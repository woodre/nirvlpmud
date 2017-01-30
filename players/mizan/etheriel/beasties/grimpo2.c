inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold, what, ring;
    ::reset(arg);
    if(arg) return;
    set_name("Grimpo");
    set_race("grimpo");
    set_alias("grimpo");
    set_short("Grimpo");
    set_ep(320000);
    set_long("You are looking at 'something'. You poke it.  It quivers,\n"+
    "changes color, and seemingly scowls at you.\n");
    set_level(14);
    set_hp(260);
    set_al(0);
    set_wc(18);
    set_ac(10);
    set_chance(60);
    set_spell_dam(30);
    set_spell_mess1("Grimpo unleashes a volley of swirling colormass.");
    set_spell_mess2("Grimpo changes color.");
    set_chat_chance(10);
    load_chat("Grimpo changes shape.\n");
    load_chat("Grimpo tells you: ykohudanrmellwofsut.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(200)+100);
    move_object(gold,this_object());
    what=clone_object("players/mizan/etheriel/items/spuckpistol.c");
    move_object(clone_object("players/mizan/etheriel/items/spuckballs"), what);
    move_object(what, this_object());
    ring=clone_object("players/mizan/etheriel/items/ringpop.c");
    move_object(ring, this_object());
}
