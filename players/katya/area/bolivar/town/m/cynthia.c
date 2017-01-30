inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(101) + 300);
  move_object(gold,this_object());

     set_name("Cynthia");
     set_short("Cynthia");
     set_race( "human");
     set_alias("cynthia");
     set_long("Cynthia is about about 5 feet 6 inches tall and weighs about\n"+
	      "141 pounds.  Her long red hair flows down her back as her bright\n"+
	      "blue eyes are kept hidden behind her brown plastic frames.\n");
     set_level(8);
     set_ac(6 + random(3));
     set_wc(11 + random(3));
     set_hp(120 + random(20));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Cynthia exclaims: Welcome to Frogs & Friends!\n");
     load_chat("Cynthia says: How many I help you today?\n");
     load_a_chat("Cynthia smiles softly.\n");

   }
} 
