inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(55) + 500);
  move_object(gold,this_object());

     set_name("Justin");
     set_short("Justin");
     set_race( "human");
     set_alias("justin");
     set_long("Justin stands about 5 feet 10 inches tall and weighs\n"+
	      "about 210 pounds.  He has short brown hair that looks\n"+
	      "as it was just buzzed off, but he does have very nice\n"+
	      "green eyes.\n");
     set_level(11);
     set_ac(8 + random(3));
     set_wc(14 + random(3));
     set_hp(150 + random(20));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Justin grumbles about being forced to go shopping.\n");
     load_chat("Justin sighs and says: Alright, let's go shopping.\n");
     load_a_chat("Justin whines and shuffles his feet.\n");

   }
} 
