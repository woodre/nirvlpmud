inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold;
    set_heart_beat(1);
    ::reset(arg);
    if(arg) return;
    set_name("Silent");
    set_race("Silent");
    set_alias("silent");
    set_short("Silent");
    set_long("Shhhh!\n");
    set_level(10);
    set_hp(160);
    set_al(0);
    set_wc(12);
    set_ac(10);
    set_chance(20);
    set_spell_dam(10);
    set_spell_mess1("You hear silence...");
    set_spell_mess2("Silent casts multicolored balls of energy burn and dig into your flesh!\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+450);
    move_object(gold,this_object());
}
