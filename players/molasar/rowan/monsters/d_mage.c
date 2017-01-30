
/*
 * DRAGONMAN MAGE (1/23/94)
 */

inherit "players/molasar/rowan/obj/monster";

reset(arg) {
   if(arg) return;
   set_name("dragonman");
   set_alias("dragon");
   set_alt_name("mage");
   set_race("dragon");
   set_short("A dragonman mage");
   set_long("One of the dreaded mages who have devoted their life\n"+
            "to the study of the dark arts.\n");
   set_level(14);
   set_hp(120);
   set_ac(4);
   set_heal(3,60);
   set_al(-100);
   set_aggressive(1);
   set_single_chance(20);  /* all chances must add up to 100 */
   set_single_dam(10);
   set_single_mess1("The dragonman bares his fangs and lunges!\n");
   set_single_mess2("The dragonman bites you!\n");
   set_number_of_attacks(2);
   set_multiple_chance(20);
   set_multiple_dam(10);
   set_multiple_mess1("The dragonman attacks with his claws!\n");
   set_multiple_mess2("You're racked across your body by sharp talons!\n");
   set_mass_chance(40);
   set_mass_dam(60);
   set_mass_divisor(1); /* if divide mass_dam among players in room */
   set_mass_mess1("The dragonman mage prepares a spell.\n");
   set_mass_mess2("A fireball explodes engulfing you in flames!\n");
   set_regular_chance(20);
   set_can_kill(1); 
   ::reset();
}

