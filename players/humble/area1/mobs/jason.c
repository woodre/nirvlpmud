/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=1000+random(1500);
    move_object(clone_object("/players/humble/area1/objs/nametag2.c"));
    move_object(clone_object("/players/humble/area1/objs/apron2.c"));
    init_command("wear apron");
    set_name(HIY+"Jason"+NORM);
    set_alt_name("jason");
    set_alias("jason");
    set_short(HIY+"Jason"+NORM);
    set_race("human");
    set_long(
    "This is Jason, he looks like a complete heroin addict.\n"+
    "He has deep bags under his eyes and his skin is grey.\n");
    set_gender("male");
    set_level(17);
    set_ac(18);
    set_wc(24);
    set_hp(400+random(200));
    set_al(350);
    set_chat_chance(6);
     load_chat(HIY+"Jason stares off into space and grins stupidly.\n"+NORM);
    set_a_chat_chance(6);
    load_a_chat(HIR+"Jason screams:"+NORM+" I'm a scrapper! My daddy used to beat me.\n"+NORM);
    }
}
