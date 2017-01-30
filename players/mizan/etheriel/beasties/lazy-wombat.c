inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("a wombat");
    set_race("wombat");
    set_short("A fat, furry wombat");
    set_long("This is a fat, furry beast that does absolutely nothing\n"+
    "but eat, sleep, and dig holes all day. It's your typical useless animal.\n");
    set_level(2);
    set_hp(35);
    set_al(0);
    set_ac(5);
    set_wc(4);
    set_chance(10);
    set_spell_dam(4);
    set_spell_mess1("A wombat tries to run away, but fails.");
    set_spell_mess2("A wombat bares its teeth at you.");
    set_chat_chance(5);
    load_chat("A wombat chomps on some dirt.\n");
    load_chat("A wombat snorts.\n");
    load_chat("A wombat nibbles on some grass.\n");
    load_chat("A wombat appears to be happy.\n");
    treasure=clone_object("obj/money.c");
    treasure->set_money(60);
    move_object(treasure, this_object());
}
