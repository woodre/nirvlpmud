inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 150);
  move_object(gold,this_object());

     set_name("Seth");
     set_short("Seth");
     set_race( "human");
     set_alias("seth");
     set_long("Seth stands about 3 feet 7 inches tall and weighs about 45\n"+
	      "pounds.  He has short hair that is nicely trimmed.  He seems\n"+
	      "very unhappy to be out here on the streets shopping.\n");
     set_level(5);
     set_ac(3 + random(3));
     set_wc(7 + random(3));
     set_hp(70 + random(10));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Seth whines: Mama, can we go home?!\n");
     load_chat("Seth whines: Mama, I wanna go home!\n");
     load_a_chat("Seth sighs unhappily.\n");
   }
} 
