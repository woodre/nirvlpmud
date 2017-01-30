inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "Rob" );
     set_alias("rob");
     set_short("Rob");
   set_long("This is a simple college student.\n");
     set_level(15);
     set_ac(12);
     set_wc(20);
     set_hp(215);
     set_al(-99);
     set_aggressive(0);
     set_chat_chance(9);
     set_a_chat_chance(20);
   load_chat("Rob says: Leave me alone...Im on the phone!.\n");
   load_chat("Rob asks you to play volleyball.\n");
   load_chat("Rob says: CLOSE THE DOOR PETE!!\n");
   load_a_chat("Rob says: Go ahead hit me again punk!\n");
   load_a_chat("Rob thinks your a putz.\n");
    load_a_chat("Rob says 'Hey Buddy!'\n");
     money = (800);
   }
}

