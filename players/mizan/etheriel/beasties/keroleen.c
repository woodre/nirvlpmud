inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("keroleen");
    set_race("frog");
    set_alias("keroleen");
    set_short("Keroleen");
    set_long("This is Kerokerokeroppi's girlfriend. She's rather cute... for a frog.\n"+
    "Hey! I'm not being racist... just... okay, I am racist. I don't like\n"+
    "frogs. Too bad.\n");
    set_level(7);
    set_hp(105);
    set_al(10);
    set_ac(6);
    set_wc(11);
    set_chance(10);
    set_spell_dam(12);
    set_spell_mess1("Keroleen screams: Help me, Kero!!");
    set_spell_mess2("Keroleen kicks you *THUMP* ugh.. that hurt...");
    set_chat_chance(10);
    load_chat("Keroleen whimpers: Kero?\n");
    load_chat("Keroleen ribbits quietly.\n");
    load_chat("Keroleen looks around helplessly.\n");
    load_chat("Keroleen goes: Whoooooooooa... This is definitely not Tokyo anymore...\n");
    weapon=clone_object("players/mizan/etheriel/items/kero-tee.c");
    move_object(weapon, this_object());
    treasure=clone_object("obj/money");
    treasure->set_money(150);
    move_object(treasure, this_object());
}
