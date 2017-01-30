#include "/players/mythos/myth/bounty/spells/def.h"
object weapon;
string type,slay;
string bstyles;
string slay_b;
int poison,flame,launch;
string short_h;

start_weapon_shadow(what) {
   weapon = what;
   bstyles = allocate(10);
   slay_b = allocate(5);
   poison = flame = launch = 0;
   shadow(weap,1);
   return 1;
}

set_type(str) { type = str; }
set_slay(str) { slay = str; }

set_poison(n) { poison = n; }
set_flame(n) { flame = n;}
set_launcher(n) { launch = n; }

set_short_h(str) { short_h = str; }

short() { string hh;
          hh = 0;
          if(poison) hh = BOLD+"P "+NORM;
          if(flame) { if(!hh) hh = RED+"F "+NORM; else hh += RED+"F "+NORM; }
          if(launch) { if(!hh) hh = GRN+"L "+NORM; else hh += GRN+"L "+NORM; }
          return hh+short_h; }

query_bounty_weapon() { return 1; }

weapon_hit(attacker) {
int meow;
string meowed;
  if(random(3) == 0 && bbG) {
    if(flame && random(3) == 0) {
    }
    if(poison && random(3) == 0) poison_targ(attacker);
    if(launch && random(3) == 0) launch_targ(attacker,tpR);
    if(atT->id(slay)) {
      if(type == "blade" || type == "distance" && random(25) < bbL) {
      }
      if(type == "hand" || type == "thrust" && random(60) < bbL) {
      }
    }
  return random(8);
  }
}
    
/* hand, blade, thrust, distance */


poison_targ(ob) {
object targ,counter;
  targ = ob;
  if(!targ) return 0;
  counter = present("mbpoison",targ);
  if(counter) {
    counter->set_level(bbL);
    if(counter->query_time() < counter->query_mtime()) 
      counter->set_time(counter->query_mtime());
  } else {
    counter = clone_object("/players/mythos/myth/bounty/spells/poison.c");
    counter->set_level(bbL);
    move_object(counter,targ);
  } 
}

launch_targ(ob,me) {
object targ,missile,user;
user = me;
targ = ob;
  if(!targ) return 0;
  missile = present("bounty_grenade",user);
  if(!missile) return 0;
  user->add_weight(-missile->query_weight());
  move_object(missile,targ);
  missile->set_on();
} 