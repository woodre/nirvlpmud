inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

   move_object(clone_object("/players/daranath/weps/demon_hook.c"),this_object());
     set_name("demon");
     set_alt_name("demonling");
     set_short("A horned Demonling");
     set_race( "demon");
     set_gender("creature");
     set_long("The horned demonling is a creature summoned here from\n"+
              "another plane to preform some sort of service. The demonlings\n"+
              "are the lowest form of demons brought about in this way. Its\n"+
              "bright red skin, bat-like wings and elongated horns give\n"+
              "away its true nature.\n");
     set_level(12);

     init_command("wear armor");
     init_command("wield weapon");

     set_ac(16);
     set_wc(12 + random(4));
     set_hp(160 + random(30));
     set_al(-320);
     set_aggressive(0);
     set_a_chat_chance(25);
     load_a_chat("The demonling charges at you with its horns and hook.\n");
     load_a_chat("The demonling tears at you with its claws.\n");
     load_a_chat("The demonling gores you on its wicked hook.\n");

   }
}
