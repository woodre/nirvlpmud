inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(54) + 300);
  move_object(gold,this_object());

     set_name("Cathy");
     set_short("Cathy");
     set_race( "human");
     set_alias("cathy");
     set_long("Cathy stands about 5 feet 6 inches tall and weighs about 143\n"+
	      "pounds.  She has shoulder length brown hair that looks a little\n"+
	      "frizzy.  She has long eye lashes that brings out her green eyes.\n");
     set_level(8);
     set_ac(6 + random(3));
     set_wc(11 + random(3));
     set_hp(110 + random(10));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Cathy says: Let's go shopping!\n");
     load_chat("Cathy giggles happily!\n");
     load_a_chat("Cathy says: I need some new clothes!\n");
     load_a_chat("Cathy smiles happily!\n");
   }
} 
