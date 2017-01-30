inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 150);
  move_object(gold,this_object());

     set_name("Julie");
     set_short("Julie");
     set_race( "human");
     set_alias("julie");
     set_long("Julie about 3 feet 7 inches tall and weighs about 45\n"+
	      "pounds.  She has short hair that is nicely trimmed. \n"+
	      "she seems to be very happy playing.\n");
     set_level(5);
     set_ac(3 + random(3));
     set_wc(7 + random(3));
     set_hp(70 + random(10));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Julie giggles happily!\n");
     load_chat("Julie squeals: Come on! Let's go playout side!!\n");
     load_a_chat("Julie smiles happily.\n");
   }
} 
