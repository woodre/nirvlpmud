
#include </players/tallos/ansi.h>

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

	   
	   object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(250) + 250);
  move_object(gold,this_object());

     set_name("Halfling");
     set_short(""+HIB+"A Halfling Rogue"+NORM+"");
     set_race( "halfling");
     set_alias("rogue");
     set_long("A shifty halfling who eyes your coin pouch. He wields a "+GRN+"dagger"+NORM+".\n");
     set_level(10);
     set_ac(8 + random(2));
     set_wc(13);
     set_hp(120 + random(50));
     set_al(0);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(5);
     load_chat("The halfling trys to sneak his hand in your pocket but fails.\n");
     load_chat("The halfling takes out a dagger and plays with it between his fingers.\n");
     load_a_chat("The halfling stabs you in the back.\n");
     load_a_chat("\"You're knee caps are at me mercy!\" the halfling yells.\n");
   }
}
