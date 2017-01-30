inherit "/players/snow/closed/mech";
/* COST: 3000 */
 
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("WhirliBall");
     set_short("A WhirliBall Mech");
     set_race("mech");
     set_alias("whirliball");
     set_long(
"A ball of multi-hued titanium held aloft by an unknown force.\n"+
"This is a CyberNinja WhirliBall Mech.\n");
     set_level(8);
     set_ac(5);
     set_wc(10);
     set_hp(60);
     set_more_heal(1,1);
  set_killmsg("The WhirliBall swoops to the attack!\n");
  set_spec_attack_chance(30);
  set_spec_msg("The WhirliBall thumps into its foe!\n");
  set_spec_dam(20);
  set_damagemsg(1);
  set_follow_msg1("A whirlimech flies into the room.\n");
  set_follow_msg2("Your whirlimech hovers near you.\n");
  set_guard_msg("The WhirliBall mech flies to the attack!\n");
   }
}
