#include "/players/mosobp/define.h"
inherit "/obj/monster";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("pitcher");
   set_short("The Pitcher");
   set_race("human");
set_long(
"This pitcher has an average speed of 108 miles and hour on his fastball. He \n"+
"has an average of 10 strike outs a game. He is a feared competitor around the league.\n"+
"He stands here getting ready to throw the first warm-up pitch of the game.\n");
   set_level(15);
   set_ac(10);
   set_wc(20);
   set_hp(250);
   set_al(0);

   set_aggressive(0);
   set_chat_chance(0);
set_a_chat_chance(0);
   
   gold = clone_object("obj/money");
gold->set_money(923);
move_object(gold,this_object());
}
