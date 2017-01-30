inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/HighLevelGuard.c"

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("boink");
    set_race("boink");
    set_short("A furry Boink");
    set_long("This is a fuzzy little yellow thing that 'boinks'.\n"+
    "It has the 'personality' much like that of a precocious three\n"+
    "year old child.\n");
    set_level(3);
    set_hp(40);
    set_al(0);
    set_ac(4);
    set_wc(7);
    set_chance(10);
    set_spell_dam(4);
    set_chat_chance(5);
    load_chat("Boink boinks.\n");
    treasure=clone_object("obj/money.c");
    treasure->set_money(100);
    move_object(treasure, this_object());
}
