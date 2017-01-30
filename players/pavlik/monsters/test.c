inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "giant rat" );
     set_alias("rat");
  set_short("A Giant Rat");
set_long("An over sized rat that stares at you hungrily.\n");
     set_level(10);
     set_ac(8);
     set_wc(14);
     set_hp(150);
     set_al(-80);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(20);
  load_chat("Giant rat chews on your sock.\n");
 load_a_chat("Giant rat sinks his claws into your leg\n");
  load_a_chat("Does this thing have rabies???\n");
     money = (200);
   }
}

