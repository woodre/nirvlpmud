inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
     set_name("children");
     set_short("A group of gypsy children");
     set_race( "human");
     set_long("A small group of gypsy children with dark skin and bright eyes.\n");
     set_level(10);
     set_ac(8);
     set_wc(15);
     set_hp(150);
     set_al(600);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(10);
     load_chat("The gypsy children whisper amongst themselves.\n");
     load_chat("They gypsy children stare at you.\n");
     load_a_chat("A gypsy child dies.\n");
     load_a_chat("The gypsy children scream in terror.\n");
   }

}
