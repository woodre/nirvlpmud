inherit "/players/snow/closed/mech";
/* COST: 2000 */
 
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("FlakeMech");
     set_short("A FlakeMech");
     set_race("mech");
     set_alias("flakemech");
     set_long(
"A spinning flake of steel with keen edges.\n"+
"This is a CyberNinja FlakeMech.\n");
     set_level(5);
     set_ac(5);
     set_wc(10);
     set_hp(50);
     set_more_heal(3,5);
  set_killmsg("The FlakeMech spins to the attack!\n");
  set_guard_msg("The FlakeMech spins to defend its master!\n");
  set_spec_attack_chance(70);
  set_spec_msg("The FlakeMech spins into its foe!\n");
  set_spec_dam(15);
  set_damagemsg(2);
  set_follow_msg1("A FlakeMech spins into the room.\n");
  set_follow_msg2("Your FlakeMech spins around your head.\n");
   }
}
