inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Ms. Tisdale");
    set_alt_name("ms tisdale");
    set_race("human");
    set_alias("tisdale");
set_gender("female");
set_al(60+random(20));
    set_level(6);
    set_hp(80+random(15));
    set_wc(7+random(2));
    set_ac(3+random(3));
    set_short(BOLD+""+CYN+"Ms. Tisdale"+NORM);
    set_long(
      "Ms. Tisdale is a short lady who looks about 80 years old, but\n"+
      "is very vibrant for her age.  She is the postal carrier for Hazard\n"+
     "County.  She will make you show ID to get your mail, even if\n"+
      "she has known you for 20 years.  Ms. Tisdale has an obvious\n"+
      "crush on Jesse Duke.\n");
  gold=clone_object("obj/money");
  gold->set_money(150+random(100));
  move_object(gold,this_object());
}
