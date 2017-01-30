inherit "/players/mizan/core/container.c";
#include "/obj/ansi.h"

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(100);
    set_weight(2);

    set_max_container_weight(30);

    /* this object is limited in number! */
/*    set_limited_issue(1);*/
    /* only two at a time can be cloned in the game at all */
/*    set_limited_issue_count(2);*/
    
    set_name("bag");
    set_alias("duffel bag");

    set_short("A black duffel bag");
    set_long("This is a fairly large duffel bag made of thick black nylon. It is very\n"+
            "spacious and has some light wear on it. There is some lettering along the\n"+
            "side of the bag.\n");

    set_read("The bag is unmarked, but on the side in clear gothic print are the words:\n"+
             HIW + "Police Academy of the City of New York" + NORM + ".\n");
    set_smell("The bag tastes like NYC subway. Buh!\n");
    set_taste("You are crazy.\n");
}


