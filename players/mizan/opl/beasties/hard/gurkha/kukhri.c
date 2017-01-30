inherit "obj/weapon.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_name("kukhri");
    set_alias("knife");
    set_short("A kukhri of the " + HIW + "Royal Gurkha Rifles" + NORM);
    set_long("  This is an almost mundane, utilitarian blade of ordinary origins.\n"+
             "However you should now know that it is indeed the kukhri, a curved blade\n"+
             "barely 18 inches long that seems to have the almost perfect weight and\n"+
             "balance for cracking open coconuts, decapitating others, bushwhacking,\n"+
             "chopping firewood, opening tin cans, breaking bones, stabbing elephants,\n"+
             "bobbitizing rapists, disembowling muggers, cleaning fingernail grit, and\n"+
             "perhaps even performing lobotomies on live subjects without the use of\n"+
             "painkillers. Yes, this is a dangerously effective sucker-smoting weapon.\n");

    set_type("sword");
    set_class(21);
    set_weight(2);
    set_value(600);
    set_hit_func(this_object());
}

weapon_hit(attacker)
{
    int flag;
    flag = random(20);

    if (flag > 10)
    {
        /* The kukhri made a mess. This isn't good. Minimal return created. */
        return 1;
    }
    else if (flag > 5)
    {
        /* A bit of a cleaner kill. */
        write("The kukhri swings clean and loose in your hands...\n");
	return 3;
    }
    else if (flag > 2)
    {
        /* A much cleaner slice. The most return. */
        wriet("That felt good. The kukhri cleaves with deadly intensity.\n");
        return 6;
    }

}

/* my ONLY unbreakable weapon */
weapon_breaks()
{
    return 1;
}

query_save_flag() {
    return 1;
}

