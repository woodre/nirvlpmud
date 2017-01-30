inherit "/players/snow/closed/mech";
/* THIS IS NOT IN PLAY! This is a fun test mech for Snow... */
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("Juggernaut");
     set_short("A Juggernaut Mech");
     set_race("mech");
     set_alias("juggernaut");
     set_long(
"A fifteen foot long mass of spikes and steel blades, the Juggernaut\n"+
"Mech would be a ferocious and unstoppable opponent.\n");
     set_level(25);
     set_ac(30);
     set_wc(50);
     set_hp(1000);
     set_more_heal(20,14);
  set_guard_msg("The Juggernaut roars into combat!\n");
  set_spec_attack_chance(30);
  set_spec_msg("The Juggernaut crushes its foe!\n");
   set_spec_dam(100);
  set_follow_msg1("A Juggernaut rolls into the room.\n");
  set_follow_msg2("Your Juggernaut awaits your command.\n");
   }
}

mechtake() {
  if(this_player()->query_level() < 40) return 1;
  ::mechtake();
}
