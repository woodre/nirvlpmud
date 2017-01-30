inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("exotic dancer");
    set_alt_name("dancer");
    set_alias("girl");
    set_race("human");
    set_al(18+random(17));
    set_level(14);
    set_hp(170+random(55));
    set_wc(15+random(5));
    set_ac(9+random(4));
    set_gender("female");
    set_short(""+MAG+"An exotic dancer"+NORM+"");
    set_long(
      "This is one of the exotic dancers of the Jiggly Room.  She\n"+
      "is a cute blonde woman with a rather large chest.  This dancer\n"+
      "happens to be wearing nothing but a g-string.\n");
  gold=clone_object("obj/money");
  gold->set_money(700+random(450));
  move_object(gold,this_object());
}
