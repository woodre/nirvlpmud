inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "Devin" );
     set_alias("devin");
     set_short("Devin");
   set_long("This is a simple college student.\n");
     set_level(8);
     set_ac(7);
     set_wc(12);
     set_hp(120);
     set_al(99);
     set_aggressive(0);
     set_chat_chance(9);
     set_a_chat_chance(20);
   load_chat("Devin says: PUNK!\n");
 load_chat("Devin says: Your a putz\n");
   load_chat("Devin says: Devin=Arnold.\n");
   load_a_chat("Devin thinks your girly!.\n");
    load_a_chat("Devin says 'Hey Buddy!'\n");
     money = (300);
   }
}

