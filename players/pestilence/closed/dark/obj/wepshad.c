/*
#include "/players/snow/guild/def.h"
*/
#include "/players/pestilence/ansi.h"
#define TE tell_object
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
  gob = present("dknight_ob", wielder);
  if(gob) {
    TE(wielder, "You stop offwielding.\n");
    gob->remove_offwep();
    fwep = gob->query_firstwep();
    if(fwep) fwep->stop_wep_shadow();
    }
  shadow(weapon, 0);
  destruct(this_object());
  return 1; }

drop(str) {
  int retVal;
  retVal = (int)weapon->drop(str);
  if(!retVal)
  stop_wep_shadow();
  return retVal; }

un_wield() {
  weapon->un_wield();
  stop_wep_shadow();
  return 1; }

query_pro_weapon() { return 1; }

query_offwielded() { return 1; }

wield(str) {
  if(weapon->id(str)) {
    write("You cannot wield an offwielded weapon!\n");
    return 1; } }

dual_hit() {
  int total;
  if(!wielder || !wielder->query_weapon()) return;
  total += weapon->weapon_class();
  total += weapon->hit(myattack);
  if(total > 24) total = 24;
  dual_message(total);
  return total; }

dual_message(num) {
  int ran;
  string mess, color, weaponname;
  if(!weapon) return;
  if(!weapon->query_name()) weaponname = "weapon";
else
  weaponname = capitalize(weapon->query_name());
  if(num > 10) color = BOLD;
  if(num > 15) color = RED;
  if(num > 20) color = BOLD+RED;
  ran = random(15);
  if(!ran || ran > 4) return;
  if(ran == 1) {
    TE(wielder,
color+"Darkness covers your "+weaponname+".\n"+NORM);
   return 1; }
  if(ran == 2) {
    TE(environment(weapon), 
color+"You swing the "+weaponname+" with extra strength.\n"+NORM);
   return 1; }
  if(ran == 3) {
    TE(environment(weapon), 
color+"Your "+weaponname+" shimmers with the power of the Darkness.\n"+NORM);
   return 1; }

  return 1; }


short() {
  return weapon->short()+" (Offwielded) "+HIK+"[DARKNESS]"+NORM; }

query_wep_shadow() { return 1; }
