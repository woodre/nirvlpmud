inherit "/players/snow/closed/mech";
/* note i have changed all other mechs the same way  - mythos */
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("LaserBall");
     set_short("A LaserBall Mech");
     set_race("mech");
     set_alias("laserball");
     set_long(
"A spinning ball of blinking lights held aloft by an unknown force.\n"+
"This is a CyberNinja LaserBall Mech.\n");
      /* level changed 
     set_level(20);
     */
     set_level(8);
     /* 
     set_ac(15);
     changed to follow the pet rules - mythos <6-20-96> */
     set_ac(5);
     /* wc and hp changed to become better 
     set_wc(5);
     set_hp(50);
     */
     set_wc(15);
     set_hp(175);
     /* changed heal rate
     set_more_heal(5,1);
     */
     set_more_heal(10,15);
  set_heart_beat(1);
  set_killmsg("The LaserBall mech screams to the attack!\n");
  set_guard_msg("Lasers powering up, the LaserBall mech flies to the fray!\n");
  set_spec_attack_chance(25);
  set_spec_msg("The LaserBall cuts into its target with laserfire!\n");
  /* damage amount changed
  set_spec_dam(40);
  */
  set_spec_dam(random(30));
  set_damagemsg(3);
  set_follow_msg1("A LaserBall mech flies into the room.\n");
  set_follow_msg2("Your LaserBall mech hovers near you.\n");
   }
}
 
