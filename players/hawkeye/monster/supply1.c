inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "supply" );
     set_short("A Supply Sergeant");
     set_long("A Supply Sergeant\n");
     set_alias("sergeant");
     set_level(21);
     set_ac(19);
     set_wc(32);
     set_hp(550);
     set_al(-1000);
     set_aggressive(0);
     money = (1500);
   }
}
