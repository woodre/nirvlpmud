inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("sheriff little");
    set_alt_name("sheriff");
    set_race("human");
    set_alias("little");
set_gender("male");
    set_al(-(110+random(100)));
    set_level(15);
    set_hp(215+random(30));
    set_wc(17+random(5));
    set_ac(10+random(3));
    set_short(BOLD+""+GRN+"Sheriff Little"+NORM);
    set_long(
      "Sheriff Little is a big black man who is built like a bull, and\n"+
      "twice as mean.  He's wearing his sheriff's uniform, a smokey\n"+
     "hat, and dark sunglasses.  He is the sheriff of Chickasaw County,\n"+
      "and would love nothing more than to nail those Duke boys for\n"+
      "violating their probation and crossing the county line.\n");
  gold=clone_object("obj/money");
  gold->set_money(820+random(320));
  move_object(gold,this_object());
}
