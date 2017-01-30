inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/RandomMove.c"

reset(arg) 
{
    object weapon;
    string temp;
    ::reset(arg);
    if(arg) return;
    set_heart_beat(1);
    set_name("waldo");
    set_race("waldo");
    set_short("Waldo the Elusive");
    set_long("Dressed in a red and white striped rugby shirt, Waldo has the vaunted\n"+
    "ability of travelling about this area with little difficulty.\n"+
    "For some reason, he tends to blend into the environment, making it\n"+
    "hard to pick out among the swarms of Spuckballs and Oofas.\n");
    set_level(9);
    set_hp(135);
    set_al(320);
    set_ac(7);
    set_wc(13);
    set_chance(25);
    set_spell_dam(15);
    set_spell_mess1("Waldo screams: Ouch! That smarts!");
    set_spell_mess2("Waldo panics.");
    weapon=clone_object("obj/money");
    weapon->set_money(70+random(50));
    move_object(weapon, this_object());
    move_object(clone_object("players/mizan/etheriel/items/dopey-hat.c"), this_object());
    move_object(clone_object("players/mizan/etheriel/items/quest_puck.c"), this_object());
    temp=call_other("players/mizan/closed/RandomRoomDM.c", "one_random");
    move_object(this_object(), "/players/mizan/etheriel/ROOMS/" + temp);
}

