#include "/players/pestilence/ansi.h"
/*
#include "/players/snow/guild/def.h"
*/
#define USER ENV()
#define myattack environment(weapon)->query_attack()
object weapon, wielder;

start_wep_shadow(object ob) {
  if(!ob) return;
  if(!environment(ob)) return;
  if(!environment(ob)->is_player()) return;
  weapon = ob;
  wielder = environment(weapon);
  shadow(weapon, 1);
  return 1; }

stop_wep_shadow() {
  object gob, fwep;
  if(!wielder) return;
  gob = present("destroyer_ob", wielder);
  if(gob) {
/*
    TE(wielder, "You stop wielding.\n");
*/
    gob->remove_offwep();
    }
  shadow(weapon, 0);
  destruct(this_object());
  return 1; }

drop(str) {
  weapon->drop(str);
  stop_wep_shadow();
  return 0; }

un_wield() {
  weapon->un_wield();
  stop_wep_shadow();
  return 1; }

proficiency_hit(){
 int total;
 total = present("destroyer_ob",this_player())->query_combat() * 2;
 return total;
 }

query_pro_weapon() { return 1; }




short() {
  return weapon->short()+" "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM+""; }

query_wep_shadow() { return 1; }
