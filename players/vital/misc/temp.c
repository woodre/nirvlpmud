#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"

inherit "obj/weapon";

int hit, heal, n;

reset (arg)
{
    set_short("sword");
     set_class(17);
     set_weight(3 + random(4));
     set_long("  This sword glows with warmth, and you feel much better after\n\
 holding it for awhile.  It is the most gigantic sword you\n\
 have ever seen, so you will have to strain to carry it.\n");
     set_value(random(1000) + 999);
     set_hit_func(this_object());
}

short() { return; }

weapon_hit(attacker)
{
    int i;
    object gob;
    if(this_player()->query_guild_name() == "vampire")
    {
        if(gob = present("fangs", this_player())) 
        {
            gob->add_BLOODPTS(2);
            write(RED + "Blood" + NORM + " flows down the weapon into your hands.\n");
            return 0;
        }
    }
    i = random(20);
       if(i<4)
    {
        heal = random(7);
        call_other(this_player(), "add_hit_point", heal);
        write("You feel rejuvenated by the power of the sword.\n");
    }
    return 1;
}
