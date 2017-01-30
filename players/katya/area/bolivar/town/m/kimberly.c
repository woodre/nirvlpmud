inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(54) + 350);
  move_object(gold,this_object());

     set_name("Kimberly");
     set_short("Kimberly");
     set_race( "human");
     set_alias("kimberly");
     set_long("Kimberly stands about 5 feet 3 inches tall and weighs about\n"+
	      "130 pounds.  Her long black hair flows down her back as her\n"+
	      "deep blue eyes are kept hidden behind her black wire frames.\n");
     set_level(9);
     set_ac(6 + random(3));
     set_wc(12 + random(3));
     set_hp(100 + random(10));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Kimberly says: Let's go shopping!\n");
     load_chat("Kimberly giggles happily!\n");
     load_a_chat("Kimberly says: I want to buy lots of cool stuff!\n");
     load_a_chat("Kimberly smiles happily!\n");
   }
} 
