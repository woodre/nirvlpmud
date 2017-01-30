inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(54) + 350);
  move_object(gold,this_object());

     set_name("Samantha");
     set_short("Samantha");
     set_race( "human");
     set_alias("samantha");
     set_long("Samantha stands about 5 feet43 inches tall and weighs about\n"+
	      "130 pounds.  Her short brown hair barely reaches her shoulders.\n"+
	      "She wears contacts which make her eyes look a little brighter\n"+
              "green than they really are.\n");
     set_level(9);
     set_ac(6 + random(3));
     set_wc(12 + random(3));
     set_hp(100 + random(10));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Samantha says: Let's go shopping!\n");
     load_chat("Samantha says: Stop your complaining and come on!\n");
     load_a_chat("Samantha sighs deeply!\n");
     load_a_chat("Samantha says: We will go home when I'm done!\n");
   }
} 
