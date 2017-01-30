inherit "/players/snow/closed/mech";
 
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("RollingMech");
     set_short("A RollingMech");
     set_race("mech");
     set_alias("rollingmech");
     set_long(
"A mass of iron rolling around somehow.\n"+
"This is a CyberNinja RollingMech.\n");
     set_level(8);
     set_ac(5);
     set_wc(15);
     set_hp(175);
     set_more_heal(10,15);
  set_killmsg("The RollingMech rolls to the attack!\n");
  set_guard_msg("The RollingMech rolls to defend its master!\n");
  set_spec_attack_chance(30);
  set_spec_msg("The RollingMech rolls into its foe!\n");
  set_spec_dam(random(25));
  set_damagemsg(1);
  set_follow_msg1("A RollingMech rolls into the room.\n");
  set_follow_msg2("Your RollingMech rolls next to you.\n");
   }
}
