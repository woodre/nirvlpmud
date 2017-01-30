inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("Boofer");
    set_race("boofer");
    set_ep(600000);
    set_alias("boofer");
    set_short("Boofer");
    set_long("   This is a Boofer. It is making all sorts of funny noises.\n");
    set_level(16);
    set_hp(440);
    set_al(100);
    set_wc(24);
    set_ac(14);
    set_chance(20);
    set_spell_dam(10);
    set_spell_mess1("Boofer blinks quietly.");
    set_spell_mess2("Boofer thwops you silly!");
    set_chat_chance(20);
    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
    weapon=clone_object("players/mizan/etheriel/items/purple-stick.c");
    move_object(weapon, this_object());
    armor=clone_object("players/mizan/etheriel/items/spucksuit.c");
    move_object(armor, this_object());
}
