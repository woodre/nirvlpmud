inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 100);
  move_object(gold,this_object());

     set_name("Ann");
     set_short("Ann");
     set_race( "human");
     set_alias("ann");
     set_long("Ann stands about 4 feet 2 inches tall and weighs about\n"+
	      "43 pounds.  She has long straight, reddish blonde hair\n"+
	      "that is neatly pulled back in pig tails.  She seems \n"+
	      "very happy to be out here playing with her friends.\n");
     set_level(4);
     set_ac(3 + random(2));
     set_wc(7 + random(2));
     set_hp(50 + random(9));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Ann giggles excitedly!\n");
     load_chat("Ann says: Let's play in here!\n");
     load_a_chat("Ann smiles.\n");
   }
} 
