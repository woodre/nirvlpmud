#include "/players/mythos/closed/guild/def.h"
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("aura_of_shape");
    set_class(18);
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
  write("You strike out with your powerful claws!\n");
  say("The "+BOLD+"Dragon"+NORM+" strikes out with powerful claws- rending flesh!\n");
  tell_object(attacker,"Powerful claws rip into your flesh!\n");
  command("scream",attacker);
  attacker->heal_self(-2);
  return 0;
  }
  if(1==nm) {
  write("You lash out with your long tail- smashing your foe to the ground!\n");
  say(capitalize(attacker->query_name())+" is smashed to the ground by the "+BOLD+"Dragon"+NORM+
  "'s great tail!\n");
  command("scream",attacker);
  return 0;
  }
  if(2==nm) {
  write("You take a huge bite out of your foe's body\n");
  say("The "+BOLD+"Dragon"+NORM+" takes a bite with its great jaws!\n");
  command("scream",attacker);
  attacker->heal_self(-4);
  return 0;
  }
  return 0;}
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
