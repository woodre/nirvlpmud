inherit "/players/mizan/core/monster.c";
#include "/players/bastion/closed/color.h"

reset(arg) 
{
    object treasure;
    ::reset(arg);
    if(arg) return;
    set_name("a light bulb");
    set_race("light bulb");
    set_alias("bulb");
    set_short("An animated "+YELLOW+"light bulb"+OFF);
    set_long("Hmm... another baby-wizzy's construct running loose. You'd better\n"+
    "kill it before it electrocutes somebody.\n");
    set_level(1);
    set_hp(15);
    set_al(-10);
    set_ac(3);
    set_wc(5);
    set_chance(10);
    set_spell_dam(2);
    set_spell_mess1("The light bulb "+BLINK+"electrocutes"+OFF+" you! OUCH!!!");
    set_chat_chance(20);
    load_chat("The light bulb fuzzles noisily.\n");
    load_chat("The light bulb blinks "+BLINK+"on"+OFF+" and "+BLUE+"off"+OFF+".\n");
    treasure=clone_object("obj/money");
    treasure->set_money(30);
    move_object(treasure, this_object());
}
