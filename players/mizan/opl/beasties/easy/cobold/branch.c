inherit "obj/weapon";
#include "/obj/ansi.h"

reset(arg)
{
    ::reset(arg);
    if (!arg)
    {
        set_name("branch");
        set_long("    Behold. The Branch of Wisdom. It is a special, special weapon indeed.\n"+
                 "Actually... it is nothing more than a sawed off section of a two-by-four,\n"+
                 "conveniently sanded down a bit so that splinters don't interfere with your\n"+
                 "'instructional classes' on others.\n");
        set_short(HBWHT + HIK + "The Branch of Wisdom" + NORM);
        set_class(17);
        set_value(1500);
        set_alias("2x4");
        set_weight(2);
	set_hit_func(this_object());
    }
}

weapon_hit(attacker)
{
    if(random(100) < 20)
    {
        say(HBWHT + HIK + "The Branch of Wisdom cries: WHEN WILL YOU BASTARDS EVER LEARN!" + NORM + "\n");
        write(HBWHT + HIK + "The Branch of Wisdom BEAMS with BEATING POWER!" + NORM + "\n");
        return 5;
    }
}
