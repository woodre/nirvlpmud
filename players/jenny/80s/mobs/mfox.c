inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "michael j fox" ||  str == "michael" || str == "fox" || str == "mike" || str == "Michael J. Fox"; } 

reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Michael J. Fox");
    set_race("human");
set_gender("male");
    set_al(50+random(17));
    set_level(14);
    set_hp(200+random(20));
    set_wc(17+random(3));
    set_ac(10+random(3));
    set_short(BOLD+HIB+"Michael J. Fox"+NORM);
    set_long(
      "Michael J. Fox is a short, boyish looking young man with light\n"+
      "brown hair.  He is wearing a pair of blue jeans and a white shirt.\n"+
      "Throughout the 1980's, he stared in 'family ties'.  He was also\n"+
      "in several successful movies, including 'Back to the Future',\n"+
     "'Teen Wolf', and 'The Secret of My Success'.\n");
  gold=clone_object("obj/money");
  gold->set_money(200+random(100));
  move_object(gold,this_object());
MOCO("/players/jenny/80s/items/cooler.c"),this_object());
}
