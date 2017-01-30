inherit "/players/mizan/core/container.c";
#include "/obj/ansi.h"

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(100);
    set_weight(1);

    set_max_container_weight(30);

    set_save_flag(1);
    /* this object is limited in number! */
    set_limited_issue(1);
    /* only two at a time can be cloned in the game at all */
    set_limited_issue_count(10);
    
    set_name("pouch");
    set_alias("blue pouch");

    set_short("A blue pouch");
    set_long("This is a fairly large blue pouch made of some unknown material. It is very\n"+
            "spacious and has some light wear on it. There is some lettering along the\n"+
            "side of the bag.\n");

    set_read("The pouch is unmarked, but on the side in gothic print are the words:\n"+
             HIY + "Strummhannen Taus" + NORM + ".\n");
    set_smell("The bag tastes like... strawberries. Buh!\n");
    set_taste("You are a nutjob.\n");
}


