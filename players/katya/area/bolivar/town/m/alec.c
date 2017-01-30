inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(55) + 400);
  move_object(gold,this_object());

     set_name("Alec");
     set_short("Alec");
     set_race( "human");
     set_alias("alec");
     set_long("Alec stands about 6 feet 1 inches tall and weighs about\n"+
	      "210 pounds.  He has short brown hair that is nicely cut\n"+
	      "and has handsome green eyes.\n");
     set_level(10);
     set_ac(7 + random(3));
     set_wc(13 + random(3));
     set_hp(140 + random(20));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Alec says: We have to go buy something for your Mother.\n");
     load_chat("Alec sighs and says:  I hate shopping.\n");
     load_a_chat("Alec whines and shuffles his feet.\n");

   }
} 
