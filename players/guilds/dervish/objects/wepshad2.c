#include "../defs.h"
#define myattack environment(weapon)->query_attack()
object weapon, wielder;

start_wep_shadow(object ob) {
  if(!ob) return;
  if(!environment(ob) || !environment(ob)->is_player()) return;
  wielder = environment(ob);
  weapon = ob;
  shadow(weapon, 1);
  return 1; }

stop_wep_shadow() {
  object gob, owep;
  if(!wielder) return;
  gob = present("dervish_tattoo", wielder);
  if(!gob) gob = present("gob", wielder);
  if(gob) {
    gob->remove_firstwep(0);
    owep = gob->query_offwep();
    if(owep) wielder->stop_offwielding();
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

stopwield(str) {
  weapon->stopwield(str);
  stop_wep_shadow();
  return 1; }

un_wield(str) {
  weapon->un_wield(str);
  stop_wep_shadow();
  return 1; }

wield(str) {
  if(weapon->id(str)) {
    write("You cannot wield an offhanded weapon!\n");
    return 1; } }

query_message_hit(num) {
  string *mess;
  object weptwo, gob, me, myatt;
  int damage1, damage2;
  damage1 = random(num);
  damage2 = num - damage1;
  if(!wielder) return;
  myatt = wielder->query_attack();
  gob = present("dervish_tattoo", wielder);
  if(!gob) gob = present("gob", wielder);
  weptwo = gob->query_offwep();
  if(!weptwo) { stop_wep_shadow(); return; }
  mess = weptwo->query_message_hit(damage2);
  if(!mess) mess = wielder->query_message_hit(damage2);
  tell_object(wielder, "You "+mess[1]+" "+myatt->query_name()+mess[0]+".\n");
  tell_object(myatt, wielder->query_name()+" "+mess[1]+" you"+mess[0]+".\n");
  room_tell(wielder, myatt,
      wielder->query_name()+" "+mess[1]+" "+myatt->query_name()+mess[0]+".\n");
  return weapon->query_message_hit(damage1);
}

room_tell(object ob, object ob2, string rmsg) {
  object allroom;
  int i;
  allroom = all_inventory(environment(ob));
  for(i=0; i < sizeof(allroom); i++) {
    if(allroom[i] != ob && allroom[i] != ob2)
       tell_object(allroom[i], rmsg); }
  return 1; }

query_wep_shadow2() { return 1; }