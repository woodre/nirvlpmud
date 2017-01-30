#include "../defs.h"
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
  gob = present("dervish_tattoo", wielder);
  if(!gob) gob = present("gob", wielder);
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
    return retVal;
}

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
  total += weapon->hit(wielder->query_attack());
 if(present("dervish_tattoo", wielder))
  dual_message(total);
  return total; }

dual_message(num) {
  int ran;
  string mess, color, weaponname;
  if(!weapon) return;
  if(!weapon->query_name()) weaponname = "weapon";
else
  weaponname = capitalize(weapon->query_name());
  if(num > 20) color = BOLD+RED;
  else if(num > 15) color = RED;
  else if(num > 10) color = BOLD;
  else color = WHITE;
  ran = random(100);
  if(!ran || ran > 10) return;
  if(ran == 1) {
    TE(wielder,
color+"The Sands bless your "+weaponname+".\n"+OFF);
   return 1; }
  if(ran == 2) {
    TE(environment(weapon), 
color+"You twirl your "+weaponname+OFF+color+" with deadly skill.\n"+OFF);
   return 1; }
  if(ran == 3) {
    TE(environment(weapon), 
color+"Your "+weaponname+OFF+color+" glows with the power of the Sands.\n"+OFF);
   return 1; }
  if(ran == 4) {
    TE(environment(weapon), 
color+"You feel at one with the Sands.\n"+OFF);
   return 1; }
  if(ran == 5) {
    TE(environment(weapon), 
color+"Chaotic forces burn inside you.\n"+OFF);
   return 1; }
  if(ran == 6) {
    TE(environment(weapon), 
color+"Your "+weaponname+OFF+color+" twirls with the force of the Sands.\n"+OFF);
   return 1; }
  if(ran == 7) {
    TE(environment(weapon), 
color+"The Sands swirl in the ecstasy of Death.\n"+OFF);
   return 1; }
  if(ran == 8) {
    TE(environment(weapon), 
color+"Your weapons spin in twin dances of Death.\n"+OFF);
   return 1; }
  if(ran == 9) {
    TE(environment(weapon), 
color+"Your "+weaponname+OFF+color+" merges in the chaos of Sand.\n"+OFF);
   return 1; }
  return 1; }

short() {
  return weapon->short()+" (Offwielded)"; }

query_wep_shadow() { return 1; }
