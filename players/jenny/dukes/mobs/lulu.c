inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("lu lu hogg");
    set_race("human");
    set_gender("female");
    set_alias("hogg");
    set_alt_name("lu lu");
    set_al(20+random(20));
    set_level(9);
    set_hp(130+random(20));
    set_wc(10+random(3));
    set_ac(5+random(3));
    set_short(BOLD+""+WHT+"Lu Lu Hogg"+NORM);
    set_long(
      "Lu Lu is a hefty dark haired woman who is married to Boss\n"+
     "Hogg.  She is also the sister of Sheriff Rosco P. Coltrane.\n"+
   "Her and Boss Hogg fight a lot, but deep down, they love\n"+
    "each other.\n");
  gold=clone_object("obj/money");
  gold->set_money(300+random(200));
  move_object(gold,this_object());
}
