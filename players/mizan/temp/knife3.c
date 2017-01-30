/* 03/13/06 Earwax: this was a highly illegal weapon, had a 1/3 chance
 * of 'freezing' the attacker for 50+r50 seconds.  Changed the duration
 * of the freeze to 1+r3, and lowering chance to 1/15.
 */

#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("brixon");
  set_alias("knife");
  set_short("Ice Knife");
  set_long("A blade of pure magical ice.  The cold aura seems to freeze\n"+
          "everything around it...\n");
  set_class(14);
  set_weight(1);
  set_value(50);
  set_hit_func(this_object());
}

query_save_flag() { return 0;}
query_gsave() { return 1;}
cleanup() { fix_weapon(); misses = 0; hits = 0; }

weapon_hit(attacker){
/* 03/13/06 Earwax: lowered frequency.
if(random(3) == 0) {
*/
if (random(15) == 9) {
  tell_room(environment(this_object()),
  "The "+BLU+"ICE"+NORM+" knife flares and the enemy is frozen!\n");
  tell_object(attacker,"You are frozen!\n");
  move_object(clone_object("/players/mythos/closed/guild/spells/freeze.c"),attacker);
   return 7; }
   return 0;
}

init() {
  ::init();
  if(random(3) == 0 && environment(this_object()) == this_player()) {
  tell_object(this_player(),
  "The "+BLU+"ICE"+NORM+" knife flares and you are frozen!\n");
     move_object(clone_object("/players/mythos/closed/guild/spells/freeze.c"),
     this_player());
  }
}
