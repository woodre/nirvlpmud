inherit "players/mizan/core/weapon.c";
#include "/obj/ansi.h"

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("hammer");
    set_alias("mallet");
    set_short("A gigantic stone mallet of " + HIR + "Severe Nut Crushing" + NORM);
    set_long("This is a gigantic, heavy, and decidedly fearsome stone hammer.\n"+
	         "It really is made of stone! The handle however is made of a very\n"+
             "black and dense sort of steel that is cool to the touch.\n"+
             "The whole thing itself is almost 3 feet long and the head is like\n"+
             "the size of a cinder block. A sledgehammer looks puny compared to\n"+
             "this crazy thing. At the end of the hammer is a giant leather strap\n"+
             "that you could fit your head in. Wacky!\n");
    set_class(20);
    set_value(1000);
    set_weight(6);

    set_save_flag(1);
    /* this object is limited in number! */
    set_limited_issue(1);
    /* only two at a time can be cloned in the game at all */
    set_limited_issue_count(10);

    set_read("There is no discernable writing on the mallet.\n");
    set_smell("The mallet smells like strawberries.\n");
    set_taste("The mallet tastes a lot like strawberry paste...\n");
}

query_weight()
{
    if(this_player() && this_player()->is_player())
    {
        if(this_player()->query_alignment() > 500)
            return 1;
        else
            return 6;
    }
    else return 6;
}
