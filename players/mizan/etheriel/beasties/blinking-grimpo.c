inherit "/players/mizan/core/monster.c";
#include "/players/mizan/esc.h"
#define BLINK ESC + "[0m" + ESC + "[1m"+ ESC +"[5m"+ ESC +"[32m"+ ESC +"[40m"
#define UNBLINK ESC+"[0m"



reset(arg)
{
    object gold, what, ring;
    ::reset(arg);
    if(arg) return;
    set_name("Grimpo");
    set_race("grimpo");
    set_alias("grimpo");
    set_short("A "+BLINK+"blinking"+UNBLINK+" Grimpo");
    set_ep(320000);
    set_long("You are looking at 'something'. It "+BLINK+"blinks"+UNBLINK+". You poke it.\n"+
    "It quivers, changes color, and seemingly scowls at you.\n");
    set_level(14);
    set_hp(260);
    set_al(0);
    set_wc(18);
    set_ac(10);
    set_chance(60);
    set_spell_dam(30);
    set_spell_mess1("Grimpo unleashes a volley of swirling colormass.");
    set_spell_mess2("Grimpo changes color.");
    set_chat_chance(10);
    load_chat("Grimpo "+BLINK+"fades"+UNBLINK+" into the environment.\n");
    load_chat("Grimpo tells you: spre"+BLINK+"l"+UNBLINK+"kw"+BLINK+"o"+UNBLINK+"elar"+
    BLINK+"s"+UNBLINK+"iwop"+BLINK+"t"+UNBLINK+"lorme"+BLINK+"?"+UNBLINK+"\n");
    gold=clone_object("obj/money");
    gold->set_money(random(200)+500);
    move_object(gold,this_object());
    what=clone_object("players/mizan/etheriel/items/wet-noodle.c");
    move_object(what, this_object());
    ring=clone_object("players/mizan/etheriel/heals/herring.c");
    move_object(ring, this_object());
}
