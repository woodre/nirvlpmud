inherit "/players/snow/closed/mech";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("HeliShuriken");
     set_short("A HeliShuriken Mech");
     set_race("mech");
     set_alias("helishuriken");
     set_long(
"A rapidly whirling mass of deadly blades held aloft by an unknown force.\n"+
"This is a CyberNinja HeliShuriken Mech.\n");
     set_level(8);
     set_ac(5);
     set_wc(15);
     set_hp(175);
     set_more_heal(7,12);
  set_killmsg("The HeliShuriken attacks on command!\n");
  set_guard_msg(
"Blades screaming for blood, the HeliShuriken flies into combat!\n");
  set_spec_attack_chance(40);
  set_spec_msg("The HeliShuriken rips into its foe!\n");
  set_spec_dam(random(35));
  set_damagemsg(2);
  set_follow_msg1("A HeliShuriken flies into the room.\n");
  set_follow_msg2("Your HeliShuriken hovers near you.\n");
   }
}
