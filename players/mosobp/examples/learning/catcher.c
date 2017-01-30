#include "/players/mosobp/define.h"
inherit "/obj/monster";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("catcher");
   set_short("The Catcher");
   set_race("human");
set_long(
"This is one of the best catchers in the league. He is well known \n"+
"for his throwing ability. He has thrown out over 300 runners in his career.\n"+
"He has only played in thie league for 5 years.\n");
   set_level(13);
   set_ac(10);
   set_wc(20);
   set_hp(250);
   set_al(0);

   set_aggressive(0);
   set_chat_chance(0);
set_a_chat_chance(0);
   
   gold = clone_object("obj/money");
gold->set_money(888);
move_object(gold,this_object());
}
