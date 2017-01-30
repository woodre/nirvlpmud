inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(101) + 400);
  move_object(gold,this_object());

     set_name("Kristin");
     set_short("Kristin");
     set_race( "human");
     set_alias("kristin");
     set_long("Kristin stands about 5 feet 3 inches tall and weighs about\n"+
	      "130 pounds.  Her long black hair flows down her back as her\n"+
	      "deep blue eyes are kept hidden behind her black wire frames.\n");
     set_level(10);
     set_ac(7 + random(3));
     set_wc(13 + random(3));
     set_hp(130 + random(20));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Kristin says: Let's go shopping!\n");
     load_chat("Kristin giggles happily!\n");
     load_a_chat("Kristin says: I want to buy lots of cool stuff!\n");
     load_a_chat("Kristin smiles happily!\n");
   }
} 
