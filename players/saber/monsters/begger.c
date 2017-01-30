inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name("begger");
     set_short("A hungry begger");
     set_race( "human");
     set_long("A hungry looking begger.\n");
     set_gender("male");
     set_level(2);
     set_ac(3);
     set_wc(6);
     set_hp(30);
     set_al(-150);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("The begger looks up at you with sad eyes.\n");
     load_chat("The begger holds out his begging cup.\n");
     load_chat("The begger says 'alms for the poor?'\n");
     load_chat("The begger rubs his empty tummy.\n");
     load_a_chat("The begger yells 'Guards!  Guards!'\n");
     load_a_chat("The begger covers his head with his hands.\n");
   }
}
