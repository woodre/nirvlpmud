
#include </players/tallos/ansi.h>

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

	   
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(80) + 200);
  move_object(gold,this_object());

 
     set_name("Fighter");
     set_short(""+HIB+"A Dwarven Fighter"+NORM+"");
     set_race( "dwarf");
     set_alias("fighter");
     set_long("This is a dwarven fighter. He oviously has seen many battles.\n");
     set_level(9);
     set_ac(5 + random(3));
     set_wc(12);
     set_hp(140 + random(50));
     set_al(0);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(5);
     load_chat("The Dwarf says, \"Aye I killed the dragon what of it?\"\n");
     load_chat("The dwarf drinks some"+HIR+" dark ale"+NORM+".\n");
     load_a_chat("The dwarf slashes you deep with his "+YEL+"Great Axe"+NORM+"!\n");
     load_a_chat("\"If you want a fight I'll give it to ye!\" the dwarf yells.\n");
   }
}
