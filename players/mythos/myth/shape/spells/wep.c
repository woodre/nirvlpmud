#include "/players/mythos/myth/shape/def.h"
inherit "obj/weapon";
string aft,ali,tough;
string strong,med,weak;
int strong_ret,med_ret,weak_ret;

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_alt_name("myth_essence");
    set_hit_func(this_object());
    setter();
}

weapon_hit(attacker) {
  if(tp->query_attrib("wil") > random(50)) {
    if(tp->query_attrib("sta") > random(70)) {
      tell_room(etp,strong);
      stro(attacker,tp);
    return strong_ret;
    } else if(!random(3)) {
      tell_room(etp,med);
      medi(attacker,tp);
    return med_ret;
    } else {
      tell_room(etp,weak);
      wea(attacker,tp);
    return weak_ret;
    }
  }
}

query_value() { return 0; }
query_weight() { return (5+random(10)); }
query_save_flag()  { return 1; } /* just in case */
drop() { return 1; }
get() { return 0; }

init() {
  ::init();
  if(ep == tp) {
  if(find_player(tpn)) command("wield "+query_name(),ep);
  else destruct(this_object());
  }
}

wield(str) {
    if (!id(str)) {
      write(tough);
    return 1; }
    if (ep != tp) return 0;
    if (wielded) { write("You already wield it!\n"); return 1; }
    if(wield_func)
        if(!call_other(wield_func,"wield",this_object())) return 1;
    wielded_by = this_player();
    call_other(this_player(), "wield", this_object());
    wielded = 1;
    write("\n");
    say("\n");
    SOUL->retrieve();
    ep->set_title(aft);
    ep->set_pretitle("");
    ep->set_al_title(ali);
    add_action("call_re","tap");
#ifndef __LDMUD__
    add_action("addition");add_xverb("");
#else
  add_action("addition", "", 3);
#endif
    return 1;
}

stopwield() {
  write(tough);
return 1;}

unwield() {
  write(tough);
return 1;} 

un_wield() { return 1; }

re_break() { return 1; }

weapon_breaks() { return 1; }

call_re() {
  write("You call upon your animal's spirit to come to this plane.\n");
  say("There is a brlliant flash of light!\n");
  pet = clone_object("/players/mythos/myth/shape/spells/pet.c");
  pet->set_oowner(tp);
  pet->set_level();
  pet->set_ac();
  pet->set_wc();
  pet->set_hp();
  pet->special_on(3);
  pet->multiple_on();
  pet->set_exx(0);
  move_object(pet,environment(tp));
  write("It comes to your side.\n");
  call_other(this_player(), "stop_wielding");
  destruct(this_object());
return 1; }
  
