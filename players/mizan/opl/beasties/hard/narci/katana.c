inherit "obj/weapon.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

string prefix;
string suffix;
string origin;
string temper;
string otakuese_fullname;


reset(arg)
{
    ::reset(arg);
    if (arg) return;

    temper = NARCI_DM->get_temper();
    prefix = NARCI_DM->get_otakuese_prefix();
    suffix = NARCI_DM->get_otakuese_suffix();
    origin = NARCI_DM->get_otakuese_origin();

    otakuese_fullname = capitalize(prefix) + "-" + suffix;


    set_name("katana");
    set_short("Katana of " + HIW + otakuese_fullname + NORM);
    set_long("You gasp at the sight of it. This is the legendary katana of " + HIW +  otakuese_fullname + NORM + ".\n" +
	     "This gleaming sword is forged from the ancient ancestral fires of " + HIW + origin + NORM +".\n"+
	     "Its metal is an impressive, multilayer Damascene pattern which was blessed and\n"+
	     "tempered with the sacred essence of " + temper + ".\n" +
             "The handle of the sword is tight, light, and cleanly balanced. Life is good.\n");

    set_type("sword");
    set_class(18);
    set_weight(4);
    set_value(6000);
    set_hit_func(this_object());
}

weapon_hit(attacker)
{
    int flag;
    flag = random(20);

    if (flag > 10)
    {
        /* The katana made a mess. This isn't good. Minimal return created. */
        return 1;
    }
    else if (flag > 5)
    {
        /* A bit of a cleaner kill. */
	return 3;
    }
    else if (flag > 2)
    {
        /* A much cleaner slice. The most return. */
        return 6;
    }

}

query_save_flag() {
    return 1;
}
