inherit "obj/weapon";
#include "/obj/ansi.h"
#include "/players/mizan/opl/definitions.h"

reset(arg)
{
    ::reset(arg);
    if (!arg)
    {
        set_name("sword");
        set_class(18);
        set_value(1000);
        set_weight(3);
        set_short(HIY + "Yo Mama's Sword" + NORM);
        set_long(
            "    This is a beat-up, almost dingy looking sword which has definitely seen\n"+
            "better days. However it just seems like there is something interesting about\n"+
            "it, and it just might be worth keeping it around.\n");
        set_hit_func(this_object());
    }
}


weapon_hit(attacker)
{
    string insult;

    insult = MAMASNAPS_DM->query_snap();

    if (random(100) < 24)
    {
        write(HBYEL + HIK + "Your sword sings...\" " + insult + "\"" + NORM + "\n");
        say(HBYEL + HIK + (this_player()->query_name()) +
         "'s sword says: \"" + insult + NORM + "\n");
        return 3;
    }
}
