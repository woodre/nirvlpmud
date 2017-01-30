inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Calador");
 set_alias("calador");
 set_short("Calador the Archmage");
 set_long(
 "Calador is an Archmage of the Mage's Tower.  The old wizard has\n"+
 "been the tutor of young magic-users since time unknown.  His long\n"+
 "white beard nearly brushes the floor when he moves.  His intense\n"+
 "green eyes speak of the immense power this wizard has accumlated\n"+
 "over the ages.\n");
 set_level(30);
 set_ac(80);
 set_wc(80);
 set_hp(10000);
 set_al(10000);
 set_aggressive(0);
   }
}


