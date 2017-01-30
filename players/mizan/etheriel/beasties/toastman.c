inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("Powdered Toast Man");
    set_race("toast man");
    set_alias("man");
    set_short("The Powdered Toast Man");
    set_long("  This is an interesting looking fellow. He is clad in only a pair\n"+
    "of briefs, and his head is shaped like... shaped like... slices of \n"+
    "powdered toast?? Hmm....\n");
    set_level(14);
    set_hp(300);
    set_al(1000);
    set_wc(17);
    set_ac(11);
    set_chance(20);
    set_spell_dam(25);
    set_spell_mess1("A fine mist of powdered sugar engulfs you!");
    set_spell_mess2("You are pelted with bread crumbs shot from the Toast Man's armpits!!\n");
    set_chat_chance(20);
    load_chat("Powdered Toast Man exclaims: Leave everything to me!!\n");
    load_chat("Powdered Toast Man says: If you must fly, cling tenaciously to my buttocks!!\n");
    load_chat("Powdered Toast Man struts his stuff.\n");
    load_chat("Powdered Toast Man laughs happily.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+500);
    move_object(gold,this_object());
    weapon=clone_object("players/mizan/etheriel/items/cap.c");
    move_object(weapon, this_object());
    armor=clone_object("players/mizan/etheriel/items/spuckboots.c");
    move_object(armor, this_object());
}
