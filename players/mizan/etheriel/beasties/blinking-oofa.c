inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/Tracking-D.c"
#include "/players/mizan/esc.h"
#define BLINK ESC +"[0m"+ESC +"[1m"+ESC +"[5m"+ESC +"[32m"+ESC +"[40m"
#define UNBLINK ESC +"[0m"

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if(arg) return;
    set_name("Oofa");
    set_race("oofa");
    set_ep(270000);
    set_alias("oofa");
    set_short(BLINK+"A blinking Oofa"+UNBLINK);
    set_long("What is Oofa? You don't know. There are lots of things out there\n"+
    "that simply cannot be explained.\n");
    set_level(13);
    set_hp(240);
    set_al(0);
    set_wc(17);
    set_ac(10);
    set_chance(40);
    set_spell_dam(10);
    set_spell_mess1(BLINK+"Oofa smoffles you very hard."+UNBLINK);
    set_spell_mess2(BLINK+"Oofa makes an odd noise."+UNBLINK);
    set_chat_chance(10);
    load_chat(BLINK+"Oofa grinds itself.\n"+UNBLINK);
    load_chat("Oofa turns quiet suddenly.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(200)+50);
    move_object(gold,this_object());
    what=clone_object("players/mizan/etheriel/items/spuckrifle.c");
    move_object(clone_object("players/mizan/etheriel/items/spuckballs-ext2.c"), what);
    move_object(what, this_object());
}
