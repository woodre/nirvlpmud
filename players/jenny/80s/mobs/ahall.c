inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "anthony michael hall" ||  str == "anthony" || str == "hall" || str == "anthony hall" || str == "Anthony Michael Hall"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Anthony Michael Hall");
    set_race("human");
set_gender("male");
    set_al(60+random(40));
    set_level(13);
    set_hp(200);
    set_wc(17);
    set_ac(10);
    set_short(HIB+"Anthony Michael Hall"+NORM);
    set_long(
      "Anthony Michael Hall is a geeky looking young man with light\n"+
      "colored, slightly curly hair.  He was in several good movies during\n"+
       "the 80's, including 'National Lampoon's Vacation', 'Sixteen Candles',\n"+
     "'Weird Science', and 'The Breakfast Club'.\n");
MOCO("/players/jenny/80s/items/cooler.c"),this_object());
  gold=clone_object("obj/money");
  gold->set_money(90+random(20));
  move_object(gold,this_object());
}
