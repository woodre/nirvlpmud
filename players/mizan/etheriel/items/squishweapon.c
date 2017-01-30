inherit "/players/mizan/core/weapon.c";
#include "/obj/ansi.h"

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("wiffle bat");
    set_class(18);
    set_value(13000);
    set_weight(2);
    set_alias("bat");
    set_short("A " + BYEL + "yellow wiffle bat" + NORM);
    set_long("  This is an ordinary looking wiffle bat. It feels light and strong *swish*\n"+
             "  as you swing it.\n");
    set_hit_func(this_object());

    set_read("The wiffle bat has the text 'Made in USA' faintly printed on the base.\n");
    set_smell("The wiffle bat smells like bubble gum.\n");
    set_taste("The wiffle bat tastes like... plastic!\n");

    /* this object is limited in number! */
    set_limited_issue(1);
    /* only four at a time can be cloned in the game at all */
    set_limited_issue_count(50);

}

weapon_hit(attacker)
{
    if(random(100) < 7)
    {
    say(capitalize(this_player()->query_name())+" viciously pounds the hell out of some poor soul with a wiffle bat!\n");
    write("You hear your opponent scream as the bat connects!\n");
    return 2;
    }
}
