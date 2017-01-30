inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "Pete" );
     set_alias("pete");
     set_short("Pete");
   set_long("This is a simple college student.\n");
     set_level(8);
     set_ac(7);
     set_wc(12);
     set_hp(120);
     set_al(99);
     set_aggressive(0);
     set_chat_chance(9);
     set_a_chat_chance(20);
   load_chat("Pete says: I need some poptarts.\n");
   load_chat("Pete says: Dont touch my ears.!!\n");
   load_a_chat("Pete thinks your a putz.\n");
    load_a_chat("Pete says 'Hey Buddy!'\n");
     money = (300);
   }
}

