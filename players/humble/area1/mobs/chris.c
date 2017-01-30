/*HUMBLE CORPS 2004*/
#include "../defs.h"

inherit "/obj/monster";

reset(arg) {
    object gold;
    ::reset(arg);
    if (!arg)  {
       gold = clone_object("obj/money");
    money=500+random(800);
       move_object(gold,this_object());
    init_command("wear apron");
    set_name("Chris");
    set_alt_name("chris");
    set_alias("chris");
    set_short(HIM+"Chris"+NORM);
    set_race("human");
    set_long(
    "Chris is a short chubby man, in fact he resembles a tall oompa loomba.\n"+
    "He has a long nose and funny mannerisms, he is sweating like a pig.\n"+
    "My guess is he has been working this job for a very long time.\n");
    set_gender("male");
    set_level(16);
    set_ac(14);
    set_wc(22);
    set_hp(300+random(50));
    set_al(250);
    set_chat_chance(6);
    load_chat(HIW+"Chris mumbles to himself:"+NORM+" Whatever, whatever.\n");
    load_chat(HIW+"Chris tells you:"+NORM+" I don't understand how they expect us to get anything done around here\n.");
}
    }
