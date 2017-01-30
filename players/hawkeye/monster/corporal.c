inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "soldier" );
     set_alias("soldier");
     set_short("A soldier");
       set_long("This is a soldier in the army..should not be a challenge.\n");
/* Changed level from 10 to 7... as Bp below. -Snow */
     set_level(7);
     set_ac(6);
     set_wc(11);
 /* changed level from 10 to 7 -Bp */
     set_hp(200);
     set_al(-45);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(20);
    load_chat("The soldier says 'LEAVE!..Ya bother me.\n");
    load_chat("The soldier dives into a ditch..\n");
    load_chat("The soldier says, 'You're a baboon!'\n");
/* Changed money to conform to regs and add variety on these multi-cloning
   monsters. From 400 to random(100)+200  -Snow */
     money = (random(100)+200);
   }
}

