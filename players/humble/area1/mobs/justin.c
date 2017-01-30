/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=100+random(200);
    move_object(clone_object("/players/humble/area1/objs/shoppingcart1.c"));
    move_object(clone_object("/players/humble/area1/objs/nametag3.c"));
    set_name("Justin");
    set_alt_name("justin");
    set_alias("justin");
    set_short(HIW+"Justin"+NORM);
    set_race("human");
    set_long(
    "This is Justin, aka Fatboy.  He weighs at least 300 lbs and appears\n"+
    "to be in his late teens.  He walks around in the rain with his\n"+
    "sunglasses on like he is some motherfucker from the Matrix.\n"+
    "His name tag reads Helper Clerk, but he does nothing but bag\n"+
    "groceries, what a sappy fuck.\n");
    set_gender("male");
    set_level(8);
    set_ac(6);
    set_wc(10);
    set_hp(100);
    set_al(350);
    set_chat_chance(5);
    load_chat(HIW+"Justin grabs a cart and walks about the parking lot aimlessly.\n"+NORM);
    }
}
