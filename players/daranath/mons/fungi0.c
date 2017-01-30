inherit "/obj/monster";

reset(arg) {
   object gold;
   ::reset(arg);
   if (!arg) {

     set_name("myconid");
     set_short("Myconid Warrior");
     set_race("fungus");
     set_alias("warrior");
     set_gender("creature");
     set_long("The Myconid resembles a walking toadstool in human form.\n"+
              "Its flesh is bloated and spongy, and it varies in splotchy\n"+
              "colors ranging from purple to gray. Its wide feet has\n"+
              "vestigal toes and its pudgy hands have two stubby fingers\n"+
              "and a thumb on either side.\n");
     set_level(9);
     set_ac(7);
     set_wc(13);
     set_hp(120 + random(40));
     set_al(-600);
     set_aggressive(1);
     set_chat_chance(15);
     set_a_chat_chance(30);
     load_chat("The fungal warrior stares at you with an empty glare.\n");
     load_chat("The fungal warrior speaks in a clicking, chittery toungue.\n");
     load_a_chat("Spores emit from the fungal warrior.\n");
     load_a_chat("The Myconid clubs you with its powerful, stubby arms.\n");

   gold = clone_object("obj/money");
   gold->set_money(random(100) + 200);
   move_object(gold,this_object());
   }
}
