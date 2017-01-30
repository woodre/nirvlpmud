inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name("scorpion");
     set_short("Giant Scorpion");
     set_race("arachnid");
     set_gender("creature");
     set_long("The giant scorpion has a dirty dark yellow shell that is\n"+
               "stained with refuse and blood, not much of it belonging to\n"+
               "the scorpion. A pair of large, snapping claws are leveled\n"+
               "in your direction.\n");
     set_level(12);
     set_ac(10);
     set_wc(16 + random(4));
     set_hp(200 + random(30));
     set_al(-500);
     set_aggressive(1);
     set_a_chat_chance(15);
     load_a_chat("Giant Scorpion snaps at you with the dual claws.\n");
     load_a_chat("Giant Scorpion lunges at you, trying to ensnare you in the claws.\n");
     load_a_chat("The deadly stinger strikes at you!!!!\n");

   }
}
