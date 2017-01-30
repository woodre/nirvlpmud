inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("cooter davenport");
    set_alt_name("cooter");
    set_race("human");
    set_alias("davenport");
set_gender("male");
    set_al(150+random(80));
    set_level(14);
    set_hp(199+random(30));
    set_wc(17+random(3));
    set_ac(9+random(3));
    set_short(BOLD+""+RED+"Cooter Davenport"+NORM);
    set_long(
      "Cooter Davenport is a big man with dark brown hair.  He is\n"+
      "covered with dirt and grease, just as any good mechanic should\n"+
     "be.  Cooter is a lot smarter than he looks.  He is a good man,\n"+
      "you can count on him when you need help.  He is a cousin of\n"+
      "Bo and Luke Duke.\n");
  gold=clone_object("obj/money");
  gold->set_money(700+random(320));
  move_object(gold,this_object());
}
