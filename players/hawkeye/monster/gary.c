inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "Gary" );
     set_alias("gary");
     set_short("Gary");
   set_long("This is a simple college student.\n");
     set_level(80);
     set_ac(14);
     set_wc(40);
     set_hp(10000);
     set_al(-99);
     set_aggressive(0);
     set_chat_chance(9);
     set_a_chat_chance(20);
   load_chat("Gary says: You bore me...Im going to watch M*A*S*H.\n");
   load_chat("Gary says:  IIT sucks..\n");
   load_chat("Gary pokes you in the ribs.\n");
   load_a_chat("Gary knows you cant kill him\n");
   load_a_chat("Gary thinks your a putz.\n");
    load_a_chat("Gary says 'Hey Buddy!'\n");
     money = (850);
   }
}

