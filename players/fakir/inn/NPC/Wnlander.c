inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

     add_money(300+random(75));
     set_name("northlander");
     set_short("A Northlander Woman");
     set_race( "human");
     set_alias("woman");
     set_long("A female northlander seeking riches with her husband.\n");
     set_level(8);
     set_ac(5 + random(3));
     set_wc(10 + random(3));
     set_hp(100 + random(30));
     set_al(0);
    
   }
}
