inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "oliver north" ||  str == "oliver" || str == "north" || str == "marine" || str == "Oliver North"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Oliver North");
    set_race("human");
set_gender("male");
    set_al(-(150+random(50)));
    set_level(14);
    set_hp(200+random(15));
    set_wc(20);
    set_ac(10);
    set_short(BOLD+HIG+"Oliver North"+NORM);
    set_long(
      "Oliver North is a middle aged man with neatly groomed short\n"+
      "grey hair.  He is a Lieutenant Colonel in the United States Marine\n"+
     "Corps.  North was a central figure in the Iran-Contra scandal of the\n"+
      "mid-late 80's.  This was a complicated fiasco in which Congressional\n"+
      "approval for funding the Nicaraguan Contras was bypassed by\n"+
      "selling weapons to Iran, and giving the profits to the Contra rebels.\n");
  gold=clone_object("obj/money");
  gold->set_money(800+random(75));
  move_object(gold,this_object());
}
