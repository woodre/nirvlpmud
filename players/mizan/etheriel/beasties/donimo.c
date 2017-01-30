inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("donimo");
    set_race("donimo");
    set_alias("donimo");
    set_short("Donimo the Spuckhunter");
    set_long("	Fully geared up, and ready for some kills, is Donimo the Spuckhunter.\n"+
    "  Upon entering the room, he realizes that you do not belong here.\n"+
    "  He notices the card that you are carrying, and he explodes in a fit of rage!\n"+
    "Donimo has three silver stars pinned to his uniform.\n");
    set_aggressive(1);
    set_level(13);
    set_hp(200);
    set_al(-1000);
    set_wc(17);
    set_ac(9);
    set_chance(20);
    set_spell_dam(17);
    set_spell_mess1("bwup bwup bwup bwup bwup bwup! You are blasted with a shower of bullets!");
    set_spell_mess2("rachy rachy rachy rachy! The NR15 sends you reeling with pain!");
    set_chat_chance(20);
    load_chat("Donimo cries: What have you done to Uckier?!?\n");
    load_chat("Donimo cries: Die you scum!!\n");
    load_chat("Donimo screams: You're never going to get out of here alive!!\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
    weapon=clone_object("players/mizan/weapons/nx15.c");
    move_object(weapon, this_object());
}
