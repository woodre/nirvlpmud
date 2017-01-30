inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name("demon");
     set_short("A blackened Demonling");
     set_race( "demon");
     set_gender("creature");
     set_long("The blackened demonling is a creature summoned here from\n"+
              "another plane to preform some sort of service. The demonlings\n"+
              "are the lowest form of demons brought about in this way. Its\n"+
              "darkened skin is the result of living primarily within the\n"+
              "hottest areas in hell.\n");
     set_level(12);
     set_ac(16);
     set_wc(12 + random(4));
     set_hp(160 + random(30));
     set_al(-320);
     set_aggressive(1);
     set_a_chat_chance(25);
     load_a_chat("The demonling breathes a gout of flame at you.\n");
     load_a_chat("The demonling tears at you with its claws.\n");
     load_a_chat("The demonling gores you on its wicked hook.\n");

   }
}
