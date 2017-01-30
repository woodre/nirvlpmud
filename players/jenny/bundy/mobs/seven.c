inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("seven");
    set_alt_name("little brat");
    set_alias("boy");
    set_race("human");
    set_al(-200);
    set_level(10);
    set_hp(100+random(50));
    set_wc(10+random(5));
    set_ac(7+random(2));
    set_gender("male");
    set_short(""+WHT+"Seven"+NORM+"");
    set_long(
      "Seven is a young, blond haired  child that belonged to Peg's\n"+
      "relatives.  His parents were even more irresponsible than the\n"+
     "Bundy's.  Al and Peg took him into their home.  Nobody could\n"+
     "stand the little brat though, so they locked him in this closet.\n");
  gold=clone_object("obj/money");
  gold->set_money(300+random(300));
  move_object(gold,this_object());

set_chat_chance(15);
load_chat(""+BLU+"Seven screams: "+NORM+" Bud locked me in the closet!"+NORM+"\n");
}
