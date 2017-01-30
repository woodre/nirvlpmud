
/*
 * DRAGONMAN GUARD (1/23/94)
 */

inherit "players/molasar/rowan/obj/monster";

reset(arg) {
   if(arg) return;
   set_name("dragonman");
   set_alias("dragon");
   set_alt_name("guard");
   set_race("dragon");
   set_short("A dragonman guard");
   set_long("This is one of the guards of the mountain.\n");
   set_level(10);
   set_hp(150);
   set_ac(6);
   set_heal(3,90);
   set_al(-100);
   set_aggressive(1);
   set_single_chance(40);  /* all chances must add up to 100 */
   set_single_dam(15);
   set_single_mess1("The dragonman bares his fangs and lunges!\n");
   set_single_mess2("The dragonman bites you!\n");
   set_number_of_attacks(2);
   set_multiple_chance(10);
   set_multiple_dam(10);
   set_multiple_mess1("The dragonman attacks with his claws!\n");
   set_multiple_mess2("You're racked across your body by sharp talons!\n");
   set_mass_chance(10);
   set_mass_dam(20);
   set_mass_divisor(0); /* if divide mass_dam among players in room */
   set_mass_mess1("The dragonman breathes a cloud of acid!\n");
   set_mass_mess2("The acid sears your flesh!!!\n");
   set_regular_chance(40);
   set_can_kill(1);    
   ::reset();
}

