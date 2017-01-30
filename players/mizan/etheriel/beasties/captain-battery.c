inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object armor, weapon;
    ::reset(arg);
    if(arg) return;
    set_name("captain");
    set_race("captain");
    set_alias("captain");
    set_short("Captain Battery");
    set_long("This is Captain Battery! Watch out... electricity is dangerous!\n"+
    "It'll toast your eyeballs!\n"+
    "Captain Battery has a large yellow patch on his suit.\n");
    set_level(15);
    set_hp(300);
    set_al(1000);
    set_wc(20);
    set_ac(12);
    set_chance(20);
    set_spell_dam(20);
    set_spell_mess1("Captain Battery toasts your eyeballs with a ZZZZZZZZZAAAAP!");
    set_spell_mess2("Captain Battery blasts you with raw funk!");
    set_chat_chance(20);
    load_chat("Captain Battery says: Make sure you pull the plug out by grasping the PLUG!\n");
    load_chat("Captain Battery says: Recycle batteries! Save the Environment!\n");
    armor=clone_object("players/mizan/etheriel/items/captainarmor.c");
    move_object(armor,this_object());
    weapon=clone_object("players/mizan/etheriel/items/captainblade.c");
    move_object(weapon, this_object());
}
