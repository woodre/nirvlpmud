inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("otterley");
    set_race("otterley");
    set_alias("otterley");
    set_short("Otterley the Sponge");
    set_long("      You take a good look at Otterley, but you just can't figure\n"+
    "  it out. It looks like a sponge. You have the intense urge to poke it\n"+
    "  and see, but that would'nt be polite, would it?\n");
    set_level(11);
    set_hp(165);
    set_al(1000);
    set_wc(15);
    set_ac(7);
    set_chance(20);
    set_spell_dam(15);
    set_spell_mess1("Otterley exclaims: Hey buddy!!");
    set_spell_mess2("Otterley woks you hard.");
    set_chat_chance(10);
    load_chat("Otterley blinks.\n");
    load_chat("Otterley makes a soft, squishing sound.\n");
    load_chat("Otterley moggles contentedly.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
    armor=clone_object("players/mizan/etheriel/items/pingpong.c");
    move_object(armor, this_object());
    weapon=clone_object("players/mizan/etheriel/items/beano-fgn.c");
    move_object(weapon, this_object());
}
