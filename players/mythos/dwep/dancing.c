#define tp this_player()
#define eo environment(this_object())
#define tpn tp->query_real_name()
#define tl tp->query_level()
#define eeo environment(eo)
#define etp environment(tp)
#include "/players/mythos/closed/ansi.h"

inherit "obj/weapon";
int charges;

query_save_flag() { return 1; } /* NONSAVEABLE */
query_dwep() { return 1; }

reset(arg) {
::reset(arg);
  if(arg) return;
  set_name("hannya");
  set_short(RED+"Dancing Sword of the Hannya"+NORM);
  set_alias("sword");
  set_alt_name("dancing");
  set_long("A \n");
  set_value(10000);
  set_weight(20);
  set_class(21);
  charges = 5 + random(10);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if(random(3) == 0) {
  return 6; }
tp->heal_self(-3-random(3));
return; }

init() {
 ::init();
 add_action("dance","bladedance");
}

dance() {
object mon;
if(!tp->query_attack()) { write("You are not in combat!!\n"); return 1; }
if(tp->query_weapon() != this_object()) {
  write("You are not wielding the dancing blade!\n"); return 1; }
  mon = clone_object("/players/mythos/dmon/dance.c");
  mon->set_own(tpn);
  move_object(mon,etp);
  command("unwield dancing",tp);
  set_short();
  move_object(this_object(),mon);
  mon->attack_object(tp->query_attack());
  charges = charges - 1;
  if(charges < 1) destruct(this_object());
return 1; }