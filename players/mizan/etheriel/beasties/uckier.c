inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("uckier");
    set_race("uckier");
    set_alias("uckier");
    set_short("Uckier the Spuckhunter");
    set_long("	Uckier looks lost. She's starting to panic. She looks like she\n"+
    "  has just lost a fight with one of the things in this area, since she\n"+
    "  is holding plenty of ammo, but she is without a weapon, and her clothing\n"+
    "  is a tattered mess.\n"+
    "Uckier has five silver stars pinned to her suit.\n");
    set_level(15);
    set_hp(225);
    set_al(-1000);
    set_wc(20);
    set_ac(12);
    set_chance(20);
    set_spell_dam(20);
    set_spell_mess1("Uckier rips a volley of shots at you!\n");
    set_spell_mess2("Uckier grumbles: Like I'm lost enough already, dammit!\n");
    set_chat_chance(20);
    load_chat("Uckier says: Hey! You! You know the way out of here?\n");
    load_chat("Uckier fumbles with a crystal ball.\n");
    load_chat("Uckier screams: Wierdos! Everyone here is just sick!\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
    weapon=clone_object("players/mizan/etheriel/heals/rawtoast.c");
    move_object(weapon, this_object());
}
