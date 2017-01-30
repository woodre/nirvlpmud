inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "mr t" ||  str == "t" || str == "mr" || str == "Mr. T" ; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Mr. T");
    set_race("human");
set_gender("male");
    set_al(50+random(20));
    set_level(15);
    set_hp(230+random(25));
    set_wc(21+random(3));
MOCO("/players/jenny/80s/items/chains.c"),this_object());
init_command("wear chains");
    set_ac(12+random(3));
   set_ac_bonus(1);
    set_short(BOLD+HIR+"Mr. T"+NORM);
    set_long(
      "Mr. T. is a large, menacing looking black man.  He has a mohawk\n"+
      "haircut, and is wearing a red tank top, with many thick gold chains\n"+
      "around his neck.  He stared in the television series 'the A team',\n"+
      "along with the movie 'Rocky III'.\n");
  gold=clone_object("obj/money");
  gold->set_money(200+random(100));
  move_object(gold,this_object());
set_chat_chance(15);
    load_chat(HIR+"Mr. T says: "+NORM+" I pity da fool who messes with Mr. T.\n");
}
