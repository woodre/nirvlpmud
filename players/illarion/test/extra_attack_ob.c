/* This is a dummy object for providing extra attacks for weapons without calling attack()
 */

object user;
object weapon;

mixed *params;

status dying;

int add_extra_attack(object usr, object wep) {
  if(!usr) return -1; if(!wep) return -2; if((object)wep->query_wielded_by() != usr) return -3;
  user=usr;
  weapon=wep;
  params=(mixed)wep->query_params();
  params = ({"other|illarion",0,"wield_check"}) + params;
  user->RegisterWeapon(this_object(),params);
  return 1;
}

hit(arg) {
  if(dying) { /* No more weapon - no more extra attack */
    return -100;
  }
  if(weapon)
    return weapon->hit(arg);
}

wield_check(arg) {
  if(!user || !weapon || (object)weapon->query_wielded_by() != user) killme();
  return 0;
}

killme() {
  dying=1;
  call_out("killme2",1);
}

killme2() {
  if(user)
    user->RemoveWeapon(this_object());
  destruct(this_object());
}

query_silent_damage() { return dying; } /* The weapon is currently going away
                                           and should miss, don't show a message */

query_message_hit(arg) { if(weapon) return weapon->query_message_hit(arg); }