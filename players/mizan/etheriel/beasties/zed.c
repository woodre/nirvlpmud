inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("zed");
    set_race("wombat");
    set_alias("Zed");
    set_short("Zed the smelly wombat");
    set_long("I guess his description explains it all. Zed smells. Well, not only\n"+
    "does he smell... but he STINKS. He's dirty too. Bits and pieces of \n"+
    "what appears to be food cling to his matted fur. The flies are even smart\n"+
    "enough to stay away.\n");
    set_level(12);
    set_hp(170);
    set_al(0);
    set_ac(9);
    set_wc(16);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Zed smashes you with a heavy chunk of ham!");
    set_spell_mess2("Zed goes: AuuAuuAgrh! You SUCK!");
    set_chat_chance(20);
    load_chat("Zed smells. Eeeeew.\n");
    load_chat("Zed grunts noisily.\n");
    load_chat("Zed chomps on some dirt.\n");
    load_chat("Zed goes: WooAuuArghAhh What the hell d-do you want er.. huh?\n");
    load_chat("Zed goes: Uhm.... Uh.. AuuuarghArgAhh! Go away!\n");
    weapon=clone_object("players/mizan/etheriel/heals/ham.c");
    move_object(weapon, this_object());
    /*
    treasure=clone_object("players/mizan/closed/etheriel/.c");
    move_object(treasure, this_object());
    */
	}
