inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 600);
  move_object(gold,this_object());

     set_name("Dan");
     set_short("Dan");
     set_race("human");
     set_alias("dan");
     set_long("Dan is about 6 feet tall and weighs about 250 pounds and is 40\n"+
	      "years old.  He has worked at Western Auto since he was 16 years\n"+
	      "old.  He looks a bit rough on the edges.\n");
     set_level(13);
     set_ac(9 + random(3));
     set_wc(16 + random(3));
     set_hp(180 + random(10));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Dan grunts: What do you need?\n");
     load_chat("Dan peers at you quizically!\n");
     load_a_chat("Dan mumbles about you interrupting his work.\n");

   }
} 
