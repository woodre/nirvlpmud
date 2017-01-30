inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "hawkeye" );
     set_short("Benjamin Franklin Pierce");
       set_long("This is Benjamin Pierce, better known as Hawkeye.\n"+
     "You are blinded by the very bright scalpel he holds in his hand,\n"+
     "you see the shiney item and feel as though you must have it.....\n" +
    "can you get it from him?\n");
     set_alias("pierce");
     set_level(21);
set_ac(20);
set_wc(45+random(3));
     set_hp(1500);
     set_al(0);
     set_aggressive(0);
     set_a_chat_chance(5);
     load_a_chat("Hawkeye yells, 'You have interupted my sleep during a very sexy dream...you will now die!'\n");
     load_a_chat("Hawkeye exclaims, 'The only way to get my scalpel is to kill me!'\n");
     money = (1500);
   }
}
