inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("woogle");
    set_race("woogle");
    set_short("Woogle");
    set_long("The Woogle is a soft, fuzzy thing that blinks and changes\n"+
    "color occasionally. A soft aura of what appears to be charged\n"+
    "particles surrounds it.\n");
    set_level(7);
    set_hp(105);
    set_al(600);
    set_ac(6);
    set_wc(11);
    set_chance(10);
    set_spell_dam(8);
    set_spell_mess1("Woogle zaps you with a burst of static electricity!");
    set_spell_mess2("Woogle blinks and fuzzles violently.");
    set_chat_chance(5);
    load_chat("Woogle changes color.\n");
    load_chat("Woogle makes some spacey noises.\n");
    load_chat("You hear the crackle of static electricity build up around Woogle.\n");
    treasure=clone_object("obj/money.c");
    treasure->set_money(200+random(150));
    move_object(treasure, this_object());
}
