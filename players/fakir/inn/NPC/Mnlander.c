inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {


     add_money(400+ random(100));
     set_name("northlander");
     set_short("A Northlander Man");
     set_race( "human");
     set_alias("man");
     set_long("A northlander in search of fame and fortune.\n");
     set_level(10);
     set_ac(6 + random(3));
     set_wc(11 + random(3));
     set_hp(120 + random(40));
     set_al(0);
    
   }
}
