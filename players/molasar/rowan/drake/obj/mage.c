
/*
 * DARK MAGE (4/30/94)
 */

inherit "players/molasar/rowan/obj/monster";

reset(arg) {
   if(arg)
     return;
   set_name("mage");
   set_alias("evil_guard");
   set_alt_name("dark mage");
   set_short("A dark mage");
   set_long("These mages were once healers in the House of Ariand. As\n"+
   "Ariand sold his soul he sold the souls of all the people under his\n"+
   "command. The healers no longer have the power to heal, instead they\n"+
   "are empowered with magical dweomers to inflict heavy damage on all\n"+
   "beings they encounter.\n");
   set_level(20);
   set_wc(15);
   set_ac(8);
   set_hp(400);
   set_aggressive(1);
   set_al(-750);
   set_regular_chance(40);
   set_multiple_chance(30);
   set_number_of_attacks(4);
   set_multiple_dam(20);
   set_multiple_mess1("The dark mage raises his arms releasing a volley of "+
      "magical missiles!\n");
   set_multiple_mess2("Your are struck by a magic missile!\n");
   set_mass_chance(30);
   set_mass_dam(40);
   set_mass_mess1("The dake mage utters a spell and casts a fireball!\n");
   set_mass_mess2("Searing flames burn your flesh as the fireball "+
      "explodes.\n");
   ::reset();
}


