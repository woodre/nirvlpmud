
#include </players/tallos/ansi.h>

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

	   
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(150) + 300);
  move_object(gold,this_object());

     set_name("Elf");
     set_short(""+HIB+"An Elven Wizard"+NORM+"");
     set_race( "elf");
     set_alias("wizard");
     set_long("A mysterious elven man with "+RED+"red robes"+NORM+" and a long staff.\n");
     set_level(10);
     set_ac(2 + random(7));
     set_wc(14);
     set_hp(170 + random(50));
     set_al(0);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The elf moves something in his spell pouch.\n");
     load_chat("The elf looks at you and starts adding numbers together to himself.\n");
     load_a_chat("The wizard starts to chant.\n");
     load_a_chat("\"You have just made enemies with the wrong person,\" the elf says.\n");
   }
}
