#include "/players/snow/guild/def.h"
object weapon;
start_wep_shadow(object ob) {
  if(!ob) return;
  weapon = ob;
  shadow(weapon, 1);
  return 1; }
stop_wep_shadow() {
  shadow(weapon, 0);
  destruct(this_object());
  return 1; }
drop(str) {
  weapon->drop(str);
  stop_wep_shadow();
  return 1; }
stopwield(str) {
  weapon->stopwield(str);
  stop_wep_shadow();
  return 1; }
query_pro_weapon() { return 1; }
proficiency_hit(object ob) { return ob->weapon_mod(); }
query_wep_shadow() { return 1; }
