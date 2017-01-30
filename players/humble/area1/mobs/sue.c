/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=1500+random(4500);
    move_object(clone_object("/players/humble/area1/objs/friedchicken.c"));
    move_object(clone_object("/players/humble/area1/objs/apron1.c"));
    init_command("wear apron");
    init_command("wield chicken");
     set_name("Sue");
    set_alt_name("sue");
    set_alias("sue");
    set_short(HIG+"Sue"+NORM);
    set_race("human");
    set_long(
     "Sue is a middle aged woman with freckles and blond hair.  She has\n"+
    "an amazing body but when she smiles all her teeth are crooked\n"+
    "and some of them are missing. She is the manager of a strange\n"+
    "looking Deli, the lights are all off but she is running business\n"+
    "through it.  It makes you wonder what really goes on her.\n");
    set_gender("female");
    set_level(22);
    set_ac(24);
    set_wc(30);
    set_hp(550+random(150));
    set_al(350);
    set_chat_chance(5);
    load_chat(HIG+"Sue bends over, she's wearing a thong.\n"+NORM);
    load_chat(HIG+"Sue whispers to you:"+NORM+" You got any rocks son?\n ");
    set_chance(16);
    set_type("other|earth");
    set_spell_dam(50);
    set_spell_mess1(
    HIG+"Sue picks up a "+HIW+"Fried Chicken"+HIG+" and bashes her opponent over the head with it.\n"+NORM);
    set_spell_mess2(
    HIG+"Sue picks up a fried chicken with both hands and swings it over her head......\n"+NORM+
    HIB+" ++++++++++++C R U N C H++++++++++++\n "+NORM+
    HIG+"...... that wasn't no K F C, Colonel Sanders.\n"+NORM);
    }
}
