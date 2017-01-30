inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "trapper" );
     set_short("Benjamin Franklin Pierce");
    set_long("This the Trapper John McIntyre, one of Hawkeye's\n" +
       "two roomates. He looks pretty tough.\n");
    "can you get it from him?\n");
     set_alias("trapper john");
     set_level(21);
     set_ac(19);
     set_wc(32);
     set_hp(550);
     set_al(-1000);
     set_aggressive(0);
     money = (4500);
   }
}
