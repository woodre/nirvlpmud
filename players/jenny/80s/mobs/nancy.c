inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "Nancy Reagan" ||  str == "nancy reagan" || str == "nancy" || str == "reagan" || str == "first lady"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Nancy Reagan");
    set_race("human");
set_gender("female");
    set_al(40+random(10));
    set_level(14);
    set_hp(210+random(7));
    set_wc(19+random(2));
    set_ac(9);
    set_short(BOLD+HIR+"Nancy Reagan"+NORM);
    set_long(
      "Nancy Reagan is a skinny elderly woman with reddish hair.\n"+
      "She is wearing a very expensive red dress, along with black\n"+
     "high heeled shoes.  For some reason, this little old lady seems\n"+
      "very intimidating.  Nancy is the wife of President Ronald\n"+
      "Reagan.  She played a prominent role in the unsuccessful\n"+
     "anti-drug effort of the 1980's. \n");
set_chat_chance(15);
    load_chat(HIR+"Nancy Reagan says: "+NORM+" Just say no.\n");
  gold=clone_object("obj/money");
  gold->set_money(800+random(100));
  move_object(gold,this_object());
}
