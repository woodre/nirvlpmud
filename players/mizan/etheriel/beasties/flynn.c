inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("flynn the nervous chicken");
    set_race("chicken");
    set_alias("flynn");
    set_short("Flynn the nervous chicken");
    set_long("Flynn is very nervous because he owes quite a bit of money\n"+
    "to some bookies. How much money? Enough to buy... something like...\n"+
    "Switzerland... yes.. Switzerland.\n");
    set_level(10);
    set_hp(150);
    set_al(0);
    set_ac(8);
    set_wc(14);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Flynn cockles and cackles wildly!");
    set_spell_mess2("Flynn tries to fly, but being a fat chicken, fails.");
    set_chat_chance(20);
    load_chat("Flynn clucks: Hey! Who are you?\n");
    load_chat("Fly goes: Whoa.... wassat?\n");
    load_chat("Flynn makes strange clicking noises.\n");
    load_chat("Flynn panics.\n");
    weapon=clone_object("obj/money");
    weapon->set_money(400+random(150));
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/infernal-mach.c");
    move_object(treasure, this_object());
}
