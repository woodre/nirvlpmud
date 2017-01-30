inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
set_name("Zombie");
set_alias("zombie");
set_short("A Zombie");
set_long("A foul Zombie.  This monster would love to make you\n"+
 "its midnight snack.\n");
set_level(3);
set_ac(4);
set_wc(7);
set_hp(45);
set_al(-500);
set_chat_chance(1);
set_a_chat_chance(20);
 load_chat("Zombie makes awful moaning sounds.\n");
 load_chat("Zombie shuffles across the cemetary.\n");
 load_a_chat("Zombie vomits a foul green fluid on you.\n");
     money = (100);
   }
}

