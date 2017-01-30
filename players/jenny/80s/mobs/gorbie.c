inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "mikhail gorbachev" ||  str == "mikhail" || str == "gorbachev" || str == "gorbie" || str == "Mikhail Gorbachev"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Mikhail Gorbachev");
    set_race("human");
set_gender("male");
    set_al(30+random(40));
    set_level(15);
    set_hp(220+random(17));
    set_wc(19+random(3));
    set_ac(10+random(4));
    set_short(HIR+"Mikhail Gorbachev"+NORM);
    set_long(
      "Mikhail Gorbachev is an older, stocky man.  He is balding, has\n"+
      "grey hair, and a red birthmark on his head.  Mikhail is wearing\n"+
      "a black three piece suit.  Gorbachev was the leader of Russia\n"+
      "during a big part of the 80's.  He helped ease Russia from a\n"+
      "communist country to a more free society.  Americans liked\n"+
     "Gorbachev so much, many jokingly suggested he should run\n"+
     "for President here.\n");
  gold=clone_object("obj/money");
  gold->set_money(750+random(220));
  move_object(gold,this_object());
}
