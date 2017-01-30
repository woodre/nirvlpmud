inherit "obj/monster";
#include "/players/persephone/rooms.h"
object wobble;
reset (arg){
object gold;
 ::reset(arg);
  if(!arg){
   gold = clone_object("obj/money");
   gold->set_money(600+random(400));
   move_object(gold, TOB);
   set_name("citizen");
   set_alias("man");
   set_short("A Towns Man");
   set_long("A citizen of the town of Stormhold he seems extremely unhappy\n" +
            "as you examine him closely you see tears in his eyes.\n\n");
   set_level(16);
   set_wc(22);
   set_ac(13);
   set_hp(400);
   set_al(0);
   set_aggressive(0);
   set_gender("male");
   set_race("human");
   set_chat_chance(20);
   load_chat("Citizen says: This used to be such a nice town\n");
   load_chat("Citizen asks: Are you going to bring freedom to the town\n");
   load_chat("The Citizen sighs\n");
   load_chat("Citizen asks: Have you seen our mayor I hear he looks poor\n");
 }
}
second_life(){
    wobble=clone_object("players/persephone/closed/niny2");
    move_object(wobble, TPL);
    ::second_life();
}
