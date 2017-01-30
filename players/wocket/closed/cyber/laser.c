#include "/players/dune/closed/guild/DEFS.h"
inherit "/players/wocket/closed/cyber/mech.c";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("LaserBall");
     set_short("A LaserBall Mech");
     set_race("mech");
     set_alias("laserball");
     set_long(
"A spinning ball of blinking lights held aloft by an unknown force.\n"+
"This is a "+FUNKYNAME+" LaserBall Mech.\n");
     set_level(8);
     set_ac(5);
     set_wc(5);
     set_hp(50);
     set_more_heal(3,1);
  set_heart_beat(1);
  set_killmsg("The LaserBall mech screams to the attack!\n");
  set_guard_msg(
    "Lasers powering up, the LaserBall mech flies to the fray!\n");
  set_spec_attack_chance(75);
  set_spec_msg("The LaserBall cuts into its target with laserfire!\n");
  set_spec_dam(40);
  set_damagemsg(3);
  set_follow_msg1("A LaserBall mech flies into the room.\n");
  set_follow_msg2("Your LaserBall mech hovers near you.\n");
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
