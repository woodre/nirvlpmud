inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "tammy faye baker" ||  str == "tammy" || str == "baker" || str == "tammy baker" || str == "Tammy Faye Baker"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Tammy Faye Baker");
    set_race("human");
set_gender("female");
    set_al(-(70+random(70)));
    set_level(10);
    set_hp(150+random(5));
    set_wc(16);
    set_ac(6);
    set_short(RED+"Tammy Faye Baker"+NORM);
    set_long(
      "Tammy Baker is an unattractive middle aged woman, who is wearing\n"+
      "about 10 coats of makeup.  Her husband is the television evangelist,\n"+
     "Jim Baker.\n");

  gold=clone_object("obj/money");
  gold->set_money(400+random(100));
  move_object(gold,this_object());

set_chat_chance(18);
    load_a_chat("Tammy Faye cries as you hit her.\n");
}
