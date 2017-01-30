inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("griff");
    set_alt_name("Griff");
    set_race("human");
    set_al(110);
    set_level(20);
    set_hp(480+random(70));
    set_wc(28+random(5));
    set_ac(16+random(3));
    set_gender("male");
    set_short(""+RED+"Griff"+NORM+"");
    set_long(
      "Griff is Al's friend, coworker, and also a member of NO'MAM.\n"+
      "He is a large black man who is single, lonely, and sometimes\n"+
      "calls phone sex chat lines to talk to Al's Mother-in-Law.\n");
MOCO("/players/jenny/bundy/items/tot.c"),this_object());

  gold=clone_object("obj/money");
  gold->set_money(1350+random(1100));
  move_object(gold,this_object());
}
