inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("harry");
    set_race("harry");
    set_alias("harry");
    set_short("Harry the affectionate (lost)");
    set_long("This fellow looks rather agreeable, but very dazed and panicky.\n");
    set_level(10);
    set_hp(150);
    set_al(0);
    set_ac(8);
    set_wc(14);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Harry smacks you!");
    set_spell_mess2("Harry kicks you in the shins!");
    set_chat_chance(16);
    load_chat("Harry goes: Aooooooo.\n");
    load_chat("Harry says: I do not like this place.\n");
    load_chat("Harry says: I'm lost.\n");
    load_chat("Harry says: Are you lost too?\n");
    load_chat("Harry goes: I think I'm allergic.\n");
    load_chat("Harry sneezes.\n");
    /*
    set_a_chat_chance(10);
    set_a_chat("Harry screams: Heeeeeeeelp!\n");
    set_a_chat("Harry says: That smarts!\n");
    */
    treasure=clone_object("obj/money");
    treasure->set_money(300+random(50));
    move_object(treasure, this_object());
}
