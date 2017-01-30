inherit "/players/mizan/core/container.c";
#include "/obj/ansi.h"

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(1000);
    set_weight(1);

    set_max_container_weight(6);

    /* this object is limited in number! */
    set_limited_issue(1);
    /* only four at a time can be cloned in the game at all */
    set_limited_issue_count(2);
    
    set_name("purse");

    set_short(BLK + "A black slimline Strenesse [tm] purse" + NORM);
    set_long(BLK + "This is an elegant evening purse, made of a smooth black leather that\n"+
            "is glossy without overdoing it, and cool to the touch. Unlike most purses\n"+
            "made of this material, it repels fingerprints and smudges. Wicked!\n\n"+
            "The House of Gabriele Strehle (Strenesse) is not known to make handbags,\n"+
            "so this item must come from a runway collection or is one-off specialty...\n" + NORM);

    set_read(BLK + "A label on the handbags reads:\n\nStrenesse AG. Proudly handmade in Nordlingen, Germany.\n" + NORM);
    set_smell(BLK + "The purse smells like luxurious schwarzer Konig leather. Ahh!\n" + NORM);
    set_taste(BLK + "Don't do that. You look silly.\n" + NORM);
}


