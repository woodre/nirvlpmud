/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=3500+random(2000);
    move_object(clone_object("/players/humble/area1/objs/nametag1.c"));
    init_command("wear nametag");
    set_name(BLU+"Gary"+NORM);
    set_alt_name("gary");
    set_alias("gary");
    set_short(BLU+"Gary"+NORM);
    set_race("human");
    set_long(
    "This is "+BLU+"Gary"+NORM+". He is the store's 2nd manager.  He runs the\n"+
    "grocery end of the store.  Well something might have scared the bugger\n"+
    "because he is shivering here in the dark computer room all alone.\n");
    set_gender("male");
    set_level(18);
    set_ac(21);
    set_wc(25+random(2));
    set_hp(900+random(100));
    set_al(350);
    set_chat_chance(6);
    load_chat(BLU+"Gary screams:"+NORM+"Did you see that thing in the backroom"+HIB+" Freezer!\n"+NORM);
    load_chat(BLU+"Gary stutters:"+NORM+" Stt-sta-ssss-stay away from the- the- the dairy cooler.\n");
    set_a_chat_chance(5);
    load_a_chat(BLU+"Gary shouts:"+NORM+" Who the fuck you messin with Esay! Don't you know I'm loco!\n");
    set_chance(25);
    set_spell_dam(35+random(40));
    set_spell_mess1(
    HIB+"Gary"+NORM+" shuffles his feet about, dazing his opponent.\n");
    set_spell_mess2(
    HIB+"Gary shuffles his feet about in a mezmorizing pattern.\n"+NORM+
    HIR+"(((((((((((((((((((((((((((((((((((((())))))))))))))))))))))))))))))))))))))))\n"+NORM+
    HIR+"     ((((((((((((((((((((((( P U N C H )))))))))))))))))))))))))     \n"+NORM+
    HIR+"     ((((((((((((((((((((((( P U N C H )))))))))))))))))))))))))     \n"+NORM+
    HIR+"     ((((((((((((((((((((((( P U N C H )))))))))))))))))))))))))     \n"+NORM+
    HIR+"     ((((((((((((((((((((((( P U N C H )))))))))))))))))))))))))     \n"+NORM+
    HIR+"(((((((((((((((((((((((((((((((((((((())))))))))))))))))))))))))))))))))))))))\n"+NORM);
    }
}
    heart_beat() {
    ::heart_beat();
    if(attacker_ob) {
    already_fight=0;
    attack();
    already_fight=0;
    attack();
    }
}
