
#include </players/tallos/ansi.h>

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

	   
	   object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(100) + 300);
  move_object(gold,this_object());

     set_name("Half-Orc");
     set_short(""+HIB+"A Half-Orc Barbarian"+NORM+"");
     set_race( "orc");
     set_alias("barbarian");
     set_long("An ugly individual to be sure. His muscles ripple with strength.\n");
     set_level(10);
     set_ac(5 + random(3));
     set_wc(13);
     set_hp(170 + random(40));
     set_al(0);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(5);
     load_chat("The Half-Orc says, \"What are you looking at little person!?!\"\n");
     load_chat("The Half-Orc grunts loudly.\n");
     load_a_chat("The Half-Orc begins to foam at the mouth, and his eyes"+RED+" bleed"+NORM+" with anger.\n");
     load_a_chat("\"I'm gonna rip of your head off and make it my puppet!\" the Half-Orc yells.\n");
   }
}
