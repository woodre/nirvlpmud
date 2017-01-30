/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=3000+random(2000);
    move_object(clone_object("/players/humble/area1/objs/nametag2.c"));
    set_name(HIB+"Mark"+NORM);
    set_alt_name("mark");
    set_alias("mark");
    set_short(HIB+"Mark"+NORM);
    set_race("human");
    set_long(
    "Mark is a short little guy.  He looks ex military just by the way he carries\n"+
    "himself and how his hair is cut.  His eyebrows are glued to his forehead.\n"+
    "His eyeballs practically pop out of his skull and he must have\n"+
    "allergies because he is sniffing a lot.\n");
    set_gender("male");
    set_level(19);
    set_wc(28);
    set_ac(22);
    set_hp(600+random(400));
    set_al(350);
    set_chat_chance(GRN+"Mark looks at you:"+NORM+" Get the fuck out of here.\n"+NORM);
    set_chat_chance(GRN+"Mark whispers something to Debbie then stops when he sees you.\n"+NORM);
    set_a_chat_chance(7);
    load_a_chat(HIW+"Mark smacks you in the face:"+NORM+" I told ya to git boy, now you gonna learn a lesson.\n");
     set_chance(20);
    set_spell_dam(40+random(20));
    set_spell_mess1(
    HIB+"Mark grabs his opponent by the shoulders and knees him in the stomach.\n"+NORM);
    set_spell_mess2(
    HIB+"Mark grabs you by your shoulders and pulls you into his knee.\n"+NORM+
    HIG+"**********************************************************\n"+NORM+
    HIW+".............You struggle to breath.\n"+NORM);
    }
}
