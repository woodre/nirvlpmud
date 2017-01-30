inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("spuckball");
    set_race("spuckball");
    set_alias("ball");
    set_short("A Mean Spuckball");
    set_long("This is a mean-looking Spuckball, changing colors and flashing\n"+
    "in livid fashion right before your eyes...\n");
    set_level(2);
    set_hp(25);
    set_al(0);
    set_ac(3);
    set_wc(6);
    set_chat_chance(4);
    load_chat("Spuckball changes color.\n");
    load_chat("Spuckball taunts you.\n");
    load_chat("Spuckball absorbs some dust specks.\n");
    treasure=clone_object("obj/money");
    treasure->set_money(20+random(10));
    move_object(treasure, this_object());
}
