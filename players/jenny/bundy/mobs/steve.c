inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("steve rhodes");
    set_alt_name("steve");
set_alias("rhodes");
set_race("human");
    set_al(125);
    set_level(16);
    set_hp(300+random(100));
    set_wc(20+random(7));
    set_ac(12+random(3));
    set_gender("male");
    set_short(""+RED+"Steve Rhodes"+NORM+"");
    set_long(
      "Steve is Marcy's first husband.  He isn't much to look at,\n"+
      "but at least he makes money.  His job at the bank may\n"+
     "be in jeporady, he just approved a loan to Al Bundy for\n"+
     "a 976-SHOE line.\n");
set_chat_chance(15);
    load_chat(""+CYN+"Steve says: "+NORM+" I can't believe Marcy ended up with that gigolo."+NORM+"\n");
  gold=clone_object("obj/money");
  gold->set_money(1200+random(600));
  move_object(gold,this_object());
}
