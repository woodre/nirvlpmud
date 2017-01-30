inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object cash,weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("feathertone");
    set_race("kender");
    set_alias("feathertone");
    set_short("A kender named Feathertone");
    set_long("Barely three feet tall, and one of the few kender that do not\n"+
    "exhibit a burning curiousity with everything that moves, \n"+
    "Feathertone must be half human or something...\n");
    set_level(10);
    set_hp(150);
    set_al(0);
    set_ac(8);
    set_wc(14);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Feathertone kicks you in the groin!");
    set_spell_mess2("Feathertone bops you on the head with his hoopak!");
    set_chat_chance(11);
    load_chat("Feathertone tortures a Beano.\n");
    load_chat("Feathertone appears to be fascinated at his surroundings.\n");
    load_chat("Feathertone looks at you.\n");
    load_chat("Feathertone says: What's that you're holding?\n");
    load_chat("Feathertone says: My name is really supposed to be 'Featherstone'.\n");
    load_chat("Feathertone asks: Get it?\n");
    weapon=clone_object("players/mizan/etheriel/items/hoopak.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/green-cape.c");
    move_object(treasure, this_object());
    cash=clone_object("obj/money");
    cash->set_money(50);
    move_object(cash, this_object());
}
