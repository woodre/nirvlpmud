#include "../def.h"
mapping debuffs;
object victim;

extra_look() {
}

set_victim(v) {
  victim = v;
}

setup() {
  if(!debuffs) debuffs = ([]);
}

reset() {
  setup();
}

get() { return 1; }
drop() { return 1; }

id(str) { return str == DEBUFFID; }

start_emote(type) {
  COMDAEM->start_debuff_emote(victim,type);
}

add_emote(type) {
  COMDAEM->add_debuff_emote(victim,type);
}

end_emote(type) {
  COMDAEM->end_debuff_emote(victim, type);
}

effect_emote(type) {
  COMDAEM->debuff_effect_emote(victim, type);
}

add_debuff(type, str, dur) {
  if(!debuffs[type] || debuffs[type][1] == 0)
  {
    debuffs[type] = ({ str, time() + dur });
    start_emote(type);
  } else { /* debuffs can be strengthened, but with diminishing returns */
    debuffs[type][0] = (debuffs[type][0] + str) * 3 / 4;
    debuffs[type][1] = time() + ((dur + debuffs[type][1] - time()) * 3 / 4);
    add_emote(type);
  }
  if(type=="dazed")
  {
    victim->RegisterArmor(TO, ({ "physical", -debuffs[type][0], 0, "daze_emote" }));
  }
  if(type=="rot")
  {
    victim->RegisterWeaponBonus(TO, ({ "physical", -debuffs[type][0], "rot_emote" }));
  }
  
  set_heart_beat(1);
}

check_debuff(type) {
  return (debuffs[type] && debuffs[type][1])?debuffs[type][0] : 0;
}

query_debuffs() {
  return debuffs;
}

consume_debuff(type, amt) {
  debuffs[type][1] -= amt;
  if(time() > debuffs[type][1]) {
    end_debuff(type);
  }
}

end_debuff(type) {
  end_emote(type);
  if(type=="dazed")
  {
    victim->RemoveArmor(TO);
  }
  if(type=="rot")
  {
    victim->RemoveWeaponBonus(TO);
  }  
  debuffs = m_delete(debuffs, type);
}

heart_beat() {
  int x,s,t,dam;
  string *dkeys, key;
  
  if(ETO != victim) { destruct(TO); return; }
  
  dkeys = keys(debuffs);
  s=sizeof(dkeys);
  t = time();
  for(x = 0; x < s; x++) {
    key = dkeys[x];
    if(debuffs[key][1]) {
      if(t > debuffs[key][1]) {
        end_debuff(key);
      } else {
        switch(key) {
          case "bleeding":
          effect_emote(key);
          dam = debuffs[key][0]/2 + random(1+ 2*debuffs[key][0]);
          if(dam > 0 && victim->query_hp() > dam)
            victim->do_damage(({dam}), ({"other|blood"}));
        }
        /* TODO - add effects for debuffs that need it */
      }
    }
  }
}

no_exp_effect() { return 1; }

daze_emote() {
  effect_emote("dazed");
}
rot_emote() {
  effect_emote("rot");
}