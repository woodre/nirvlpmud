inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/HighLevelGuard.c"

reset(arg) 
{
    object cash,weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("a hunchback named mog");
    set_heart_beat(1);
    set_race("mog");
    set_alias("hunchback");
    set_short("A hunchback named Mog");
    set_long("Hmm... This fellow looks... how shall we say... Interesting.\n"+
    "Mog looks something like a scrambled Picasso painting.\n");
    set_level(5);
    set_hp(75);
    set_al(0);
    set_ac(5);
    set_wc(9);
    set_chance(11);
    set_spell_dam(8);
    set_spell_mess1("Mog screams: Aaaugh! You bad person!");
    set_spell_mess2("Mog tries to punch you.");
    set_chat_chance(20);
    load_chat("Mog drools.\n");
    load_chat("Mog makes strange chanting noises.\n");
    weapon=clone_object("players/mizan/etheriel/items/wood-sword.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/heals/raw-potato.c");
    move_object(treasure, this_object());
    cash=clone_object("obj/money");
    cash->set_money(2);
    move_object(cash, this_object());
}
