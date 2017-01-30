inherit "/players/snow/closed/mech";
/* COST: 12000 */
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("HeliShuriken");
     set_short("A HeliShuriken Mech");
     set_race("mech");
     set_alias("helishuriken");
     set_long(
"A rapidly whirling mass of deadly blades held aloft by an\n\
 unknown force. This is a CyberNinja HeliShuriken Mech.\n");
     set_level(8);
     set_ac(5);
     set_wc(10);
     set_hp(50);
     set_more_heal(2,1);
  set_killmsg("The HeliShuriken attacks on command!\n");
  set_guard_msg(
"Blades screaming for blood, the HeliShuriken flies into combat!\n");
  set_spec_attack_chance(60);
  set_spec_msg("The HeliShuriken rips into its foe!\n");
  set_spec_dam(30);
  set_damagemsg(2);
  set_follow_msg1("A HeliShuriken flies into the room.\n");
  set_follow_msg2("Your HeliShuriken hovers near you.\n");
   }
}

heal_self(arg) {
  int num;
  num = arg;
  if(this_player()->is_player()) {
    if(num < 0) num = 0;
    }
  ::heal_self(num);
  return 1; }

hit_player(arg) {
  int num;
  num = arg;
  if(this_player()->is_player()) {
    num = num/4; }
  ::hit_player(num);
  return num; }
