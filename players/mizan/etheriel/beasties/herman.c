inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if(arg) return;
    set_name("herman the catfish");
    set_race("catfish");
    set_alias("herman");
    set_short("Herman the catfish");
    set_long("Herman is a happy catfish. He spends his time adrift in the realm\n"+
    "locked in deep thought and contemplation. Occasionally, he might have\n"+
    "something interesting to say, especially to those new to the realm.\n");
    set_level(8);
    set_hp(120);
    set_al(141);
    set_wc(12);
    set_ac(7);
    set_chance(30);
    set_spell_mess1("Herman the catfish goes: Why?? Why??\n");
    set_spell_mess2("Herman the catfish flounders and tries to flee.\n");
    set_chat_chance(10);
    load_chat("Herman the catfish lectures: Buy some panic buttons in case you get lost.\n");
    load_chat("Herman the catfish lectures: Wimpy has strange effects here, but it works.\n"+
    "        You should use it, really...\n");
    load_chat("Herman the catfish goes: Bleh.\n");
    load_chat("Herman the catfish ponders the existence of jello in the universe.\n");
    load_chat("Herman the catfish lectures: Most of the objects have a grip on everything.\n"+
    "        Don't listen to what the stupid humans say.\n");
    load_chat("Herman the catfish makes a strange bubbling sound.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(10)+50);
    move_object(gold,this_object());
    what=clone_object("players/mizan/etheriel/items/spectacles.c");
    move_object(what, this_object());
}
