inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("frog");
    set_race("frog");
    set_alias("3eyes");
    set_short("A three-eyed frog");
    set_long("Well... I guess the short description says it all.\n"+
    "It's a three-eyed frog.\n");
    set_level(3);
    set_hp(40);
    set_al(0);
    set_ac(4);
    set_wc(7);
    set_chance(10);
    set_spell_dam(5);
    set_spell_mess1("Frog goes CHUGGARUMPH!!!!");
    set_chat_chance(10);
    load_chat("Frog blinks. Three times.\n");
    load_chat("Frog goes ribbit.\n");
    load_chat("Frog tries to catch a fly but hits one of its eyes with its tongue.\n");
    treasure=clone_object("obj/money");
    treasure->set_money(90+random(20));
    move_object(treasure, this_object());
}

