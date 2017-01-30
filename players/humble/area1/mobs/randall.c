/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=150+random(500);
    move_object(clone_object("/players/humble/area1/objs/apron2.c"));
    init_command("wear apron");
    set_name("Randall");
    set_alt_name("randall");
    set_alias("randall");
    set_short("Randall");
    set_race("human");
    set_long(
    "Randall is an elderly gentleman who looks as if he can hardly stand.\n"+
    "He is slouched over and wears thick coke-bottle glasses.  As you draw\n"+
    "nearer to this beast all you can smell is alcohol. Intersting bag boy.\n");
    set_gender("male");
    set_level(8);
    set_ac(6);
    set_wc(10);
    set_hp(100);
    set_al(350);
    }
}
