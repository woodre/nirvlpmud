inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon;
    ::reset(arg);
    if(arg) return;
    set_name("venus flytrap");
    set_race("flytrap");
    set_alias("plant");
    set_short("A giant Venus flytrap");
    set_long("It's a carnivorous plant that looks REALLY hungry...\n");
    set_level(15);
    set_hp(230);
    set_al(-1000);
    set_ac(20);
    set_wc(14);
    set_chance(25);
    set_spell_dam(15);
    set_spell_mess1("The flytrap lashes out with one of its tentacles!");
    set_spell_mess2("You are showered with a blue-green acid!");
    weapon=clone_object("obj/money");
    weapon->set_money(1200);
    move_object(weapon, this_object());
}

