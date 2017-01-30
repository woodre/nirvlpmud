inherit "/obj/monster.c";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("coy duke");
    set_alt_name("coy");
set_alias("duke");
set_race("human");
    set_level(8);
    set_wc(9+random(4));
    set_ac(6+random(3));
    set_hp(100+random(40));
    set_al(108);
    set_gender("male");
    set_short(YEL+"Coy Duke"+NORM);
    set_long(
      "Coy is a thin, young looking man.  He is about 6 feet tall, with\n"+
      "blonde hair.  Coy is dressed in blue jeans and a light colored\n"+
     "shirt buttoned about half way up.  He is a cousin of Bo and\n"+
     "Luke Duke.\n");
  gold=clone_object("obj/money");
  gold->set_money(250+random(200));
  move_object(gold,this_object());
}
