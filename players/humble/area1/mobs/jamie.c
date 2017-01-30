/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=1500+random(1000);
    move_object(clone_object("/players/humble/area1/objs/grocerybag.c"));
    init_command("wield bag");
    set_name(HIW+"Jamie"+NORM);
    set_alias("jamie");
    set_alt_name("jamie");
    set_short(HIW+"Jamie"+NORM);
    set_race("human");
    set_long(
    "She looks like a little doll, seriously, her cheeks are rosey\n"+
    "and she wears her hair in some old forgotten fashion. She smiles\n"+
    "in an akwardly pleasing way, her voice is very soft.\n"+
    "This girl is very peculiar indeed.\n");
    set_gender("female");
    set_level(16);
    set_ac(17);
    set_wc(22+random(1));
    set_hp(600+random(150));
    set_al(350);
    set_chat_chance(5);
    load_chat(HIW+"Jamie wibbles about the Floral department arranging the flowers.\n"+NORM);
    load_chat(HIW+"Jamie says:"+NORM+" I like Jason so much I'm cheating on my boyfriend with him.\n");
    }
}
