inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "Larry" );
     set_alias("larry");
     set_short("Larry");
   set_long("This is a simple college student.\n");
     set_level(8);
     set_ac(7);
     set_wc(12);
     set_hp(120);
     set_al(99);
     set_aggressive(0);
     set_chat_chance(9);
     set_a_chat_chance(20);
   load_chat("Larry says: CLOSE THE DOOR PETE!!.\n");
 load_chat("Larry says: Did susan call?\n");
   load_chat("Larry says: I goin to the pool\n");
   load_a_chat("Larry thinks your a putz.\n");
    load_a_chat("Larry says 'Hey Buddy!'\n");
     money = (300);
   }
}

