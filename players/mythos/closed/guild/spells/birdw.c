#include "/players/mythos/closed/guild/def.h"
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("aura_of_shape");
    set_class(17);
    set_weight(2);
    set_value(0);
    set_hit_func(this_object());
    call_out("check",3);
}
weapon_hit(attacker){
int nm;
  if(qtf > random(70)) {
  nm=random(5);
  if(0==nm) {
  write("You attack "+capitalize(attacker->query_name())+"with great fury!\n");
  say("A fury of feathers and talons assault "+capitalize(attacker->query_name())+"!\n");
  tell_object(attacker,"Talons rip into your flesh!\n");
  command("scream",attacker);
  attacker->heal_self(-1);
  return 0;
  }
  if(1==nm) {
  write("You lash out with your sharp beak- ripping through flesh!\n");
  say(capitalize(attacker->query_name())+" tries to fend off the sharp beak of the "+
      RED+"Blood Bird"+NORM+"!\n");
  tell_object(attacker,"The razor-like beak cuts into you!\n");
  command("scream",attacker);
  attacker->heal_self(-2);
  return 0;
  }
  if(2==nm) {
  write("Calling up "+BLU+"COLD FIRE"+NORM+" you strike at your foe!\n");
  tell_object(attacker,"The bird suddenly lunges forward at you!\n");
  say("\n\t\t"+HIC+"<<<<<<<< FLASH >>>>>>>>"+NORM+"\n\n");
  say(BLU+"COLD FIRE"+NORM+" is everywhere!\n");
  attacker->heal_self(-4);
  return 0;
  }
  return 1;}
  return -1;
}

drop() { return 1;}
get() { return 0;}

check() {
  if(broke) {
  this_object()->fix_weapon();
  command("unwield aura_of_shape",environment(this_object()));
  command("wield aura_of_shape",environment(this_object()));
  }
    call_out("check",3);
return 1; }

query_save_flag()  { return 1; }
