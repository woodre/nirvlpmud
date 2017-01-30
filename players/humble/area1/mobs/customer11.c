/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=150+random(500);
    set_name("Customer");
    set_alt_name("customer");
    set_alias("customer");
    set_short("A customer");
    set_race("human");
    set_long(
    "This is an average man, with average feet and average hands.\n"+
     "He has an average job, with an average employer\n"+
     "He lives down the street, next to doctor Sawyer.\n"+
   "His shoes are average, and his car too, the only thing\n"+
    "not so average about this man, is the size of his kazoo.\n");
    set_gender("male");
    set_level(14);
    set_ac(12+random(5));
    set_wc(12+random(12));
    set_hp(150+random(100));
    set_al(350);
    }
}
