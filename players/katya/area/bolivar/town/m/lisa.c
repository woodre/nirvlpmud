inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 250);
  move_object(gold,this_object());

     set_name("Lisa");
     set_short("Lisa");
     set_race( "human");
     set_alias("lisa");
     set_long("Lisa is about 5 feet 3 inches tall and weighs about 123 pounds.\n"+
	      "She has blonde hair that reaches to the middle of her back. \n"+
	      "Lisa is an employee of Breadeaux Pizza.  She seems very friendly!\n");
     set_level(7);
     set_ac(5 + random(3));
     set_wc(10 + random(3));
     set_hp(103 + random(10));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Lisa smiles happily!\n");
     load_chat("Lisa greets you!\n");
     load_a_chat("Lisa says: How may I help you?\n");
     load_a_chat("Lisa runs around trying to make sure everything is ready for the customers\n");
   }
} 
