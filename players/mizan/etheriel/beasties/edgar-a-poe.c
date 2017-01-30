inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("edgar allan poe");
    set_race("human");
    set_alias("edgar");
    set_short("Edgar Allan Poe");
    set_long("A celebrated author, father of the modern mystery novel,\n"+
    "Bereft of his beloved, Poe fell from grace with the bottle in\n"+
    "one hand, and gambling slips in the other.\n");  
    set_level(11);
    set_hp(165);
    set_al(25);
    set_ac(15);
    set_wc(9);
    set_chance(25);
    set_spell_dam(14);
    set_spell_mess1("Edgar Allen Poe screams at you!");
    set_spell_mess2("Edgar Allen Poe cries: Why??");
    set_chat_chance(8);
    load_chat("Edgar Allan Poe says: I feel happy... peaceful at last...\n");
    load_chat("Edgar Allan Poe sighs deeply.\n");
    load_chat("Edgar Allan Poe drifts around.\n");
    treasure=clone_object("obj/money.c");
    treasure->set_money(400+random(150));
    move_object(treasure, this_object());
}
