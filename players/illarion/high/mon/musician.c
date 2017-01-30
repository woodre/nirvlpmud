inherit "obj/monster";
#include "/players/illarion/dfns.h"

int call_int;
int already_attacked;

void reset(int arg) {
  if(arg) return;
  ::reset(arg);
  
  set_alias("bar_musician");
  set_race("human");
  set_gender(({"male","female"})[random(2)]);
  set_long("Generic long.  should be set by room.\n");
  set_level(18);
  set_hp(450+random(100));
  set_wc(26+random(4));
  set_ac(15+random(3));
  set_al(-100+random(301));
}
heart_beat() {
/* get help from other band members in the room periodically */
  if(attacker_ob && !already_attacked) {
    call_int++;
    if((call_int>10 && !random(5)) &&
                    present(attacker_ob,environment(this_object()))) {
      object *inv;
      int x,size;
      call_int=0;
      inv=all_inventory(environment(this_object()));
      inv-=({this_object()});
      size=sizeof(inv);
      for(x=0;x<size;x++)
        if(inv[x]->id("bar_musician"))
          inv[x]->do_attack_object(attacker_ob);
      already_attacked=1;
    }
  }
  ::heart_beat();
}
stop_fight() {
  already_attacked=0;
  return ::stop_fight();
}
do_attack_object(ob) {
  already_attacked=1;
  attack_object(ob);
}
