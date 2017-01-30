#include "/players/mythos/dmon/def.h"
inherit "players/mythos/dmon/mon";

int flight, mental, strat;
int dist,dist_dam;
string dist_hit,dist_ef;

set_strategy(n) { strat = n; }
query_strategy() { return strat; }
set_mental(n) { mental = n; }
query_mental() { return mental; }
set_distance(n) { dist = n; }
set_distance_damage(n) { dist_dam = n; }
set_distance_hit(str) { dist_hit = str; }
set_distance_effect(str) { dist_ef = str; }

reset(arg) {
  ::reset(arg);
  if(arg) return;
  flight = 0;
  mental = strat = 0;
  dist = dist_dam = 0;
  dist_hit = dist_ef = "";
}

heart_beat() {
  ::heart_beat();
  if(attacker_ob && !flight) { 
    if(attacker_ob->query_level() > query_level() || random(100) < mental ||
       attacker_ob->query_hp() > query_hp() ||
       (query_hp() < query_mhp()*2/3 && query_hp() > query_mhp()/10)) {
         flight = 1;
         tell_room(environment(this_object()),
         capitalize(query_name())+" takes to the air!\n"); }
  }
  if(alt_attacker_ob && !flight) {
  if(alt_attacker_ob->query_level() > query_level() + 5 ||
       alt_attacker_ob->query_hp() > query_hp() + 30) {
         flight = 1;
         tell_room(environment(this_object()),
         capitalize(query_name())+" takes to the air!\n"); }
  }
  if(flight && random(100) < mental) { 
    if(!dist && random(100) < strat && attacker_ob) {
      set_wc(query_wc() + 1);
      set_ac(query_ac() + 1);
      tell_room(environment(this_object()),
        capitalize(query_name())+" swoops down at you!\n");
    }
    if(dist == 1) { 
       if(attacker_ob) {
         tell_room(environment(this_object()),dist_ef);
         tell_object(attacker_ob,dist_hit);
         if(random(100) < strat) attacker_ob->heal_self(-(dist_dam)/2);
         else attacker_ob->hit_player(dist_dam/2);
         if(attacker_ob) attacker_ob->hit_player(dist_dam/2);        
       }
       if(alt_attacker_ob) {
         if(random(100) < strat && alt_attacker_ob != attacker_ob) {
          tell_object(alt_attacker_ob,dist_hit);
          alt_attacker_ob->hit_player(dist_dam/3);
    }} }
    if(dist == 2) {
      if(random(100) < strat) {
       object fools;
       int nf;
       fools = all_inventory(environment(this_object()));
       tell_room(environment(this_object()),dist_ef);
       for(nf=0;nf<sizeof(fools);nf++) {
         if(fools[nf] != this_object() && living(fools[nf]) && !fools[nf]->id("messenger")) {
           tell_object(fools[nf],dist_hit);
           fools[nf]->hit_player(dist_dam/4); 
           if(attacker_ob && fools[nf] && fools[nf] == attacker_ob) 
             fools[nf]->heal_self(-(dist_dam/2));
           if(fools[nf] && alt_attacker_ob && fools[nf] == alt_attacker_ob && 
              fools[nf] != attacker_ob) 
             fools[nf]->hit_player(dist_dam/2);
        }
      }
   }}
   }
   if(query_hp() > 0 && query_hp() < query_mhp()/10) {
     flight = 0;
     tell_room(environment(this_object()),
       short()+" swoops down and lands.\n");
    }
}

hit_player(dam,zap) {
int damm;
object weps,targ;
  damm = dam;
  if(flight) {
    targ = previous_object(); weps = 0;
      if(living(previous_object())) {
        if(previous_object()->query_weapon()) {
         weps = previous_object()->query_weapon();
         targ = previous_object(); }
      }
      if(weps) {
       if(weps->id("spear") || weps->id("lance") || weps->id("halberd") ||
          weps->id("naginata") || weps->id("polearm") || weps->query_thrust()) {
            damm = damm*2/3;
            tell_object(targ,
              "Your weapon falls a tad short of the flying "+capitalize(query_name())+"\n");
            }
       else if(weps->id("bow") || weps->id("gun") || weps->id("sling") ||
          weps->id("machine gun") || weps->id("launcher") ||
          weps->id("blaster") || weps->id("blowgun") || weps->id("longbow") ||
          weps->id("crossbow") || weps->id("shortbow") || weps->id("daikyu") ||
          weps->id("dart") || weps->query_distance()) damm = damm*9/10;
       else { damm = damm/10; 
              tell_object(targ,
                "Your weapon falls short of the flying "+capitalize(query_name())+"!\n");
             }
      }
      else { damm = damm/2; }
    }
  ::hit_player(damm,zap);
}

heal_self(n) {
int h;
  h = n;
  if(flight && h < 0) h = h/2;
  ::heal_self(h);
}