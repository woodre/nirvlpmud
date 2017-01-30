inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 100);
  move_object(gold,this_object());

     set_name("Lillith");
     set_short("Lillith");
     set_race( "human");
     set_alias("lillith");
     set_long("Lillith stands about 3 feet 7 inches tall and weighs about\n"+
	      "30 pounds.  She has long curly, brown hair that is neatly\n"+
	      "put in pig tails.  She seems very unhappy to be out here\n"+
	      "on the streets shopping.\n");
     set_level(4);
     set_ac(3 + random(2));
     set_wc(7 + random(2));
     set_hp(50 + random(9));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Lillith whines: Daddy, can we go home?!\n");
     load_chat("Lillith whines: Daddy, I wanna go home!\n");
     load_a_chat("Lillith sighs unhappily.\n");
   }
} 
