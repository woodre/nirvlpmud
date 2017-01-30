#include "/players/mythos/myth/bounty/spells/def.h"
string slayd;
string bstyles;
string slay_bstyles;
int poison;

set_slay(str) { slayd = str; }

set_poison(n) { poison = n; }

long() { ::long();
         if(poison) write(BOLD+"Poisoned  "+NORM);
         write("\n");
       }
       
short() { string h;
          h = 0;
          if(poison) h = BOLD+"P "+NORM;
          if(!h) h = short(); else h += ::short();
          return h+RED+" ["+slayd+" slayer]"+NORM; }

query_bounty_weapon() { return 1; }

reset(arg) {
    ::reset(arg);
    if (arg) return;
    poison  = 0;
    bstyles = allocate(10);
    slay_bstyles = allocate(5);
    
}

weapon_hit(attacker) {
int meows;
string meowm;
  if(random(3) == 0 && bbG) {
    meows = random(10);
    meowm = bstyles[meows];
    tell_room(etP,meowm+NORM+"\n");
    if(poison && random(3) == 0) poison_targ(attacker);
    if(atT->id(slayd) && random(25) < bbL) {
      meows = random(5);
      meowm = slay_bstyles[meows];
      ahS(-random(bbL/2));
      tell_room(etP,meowm+NORM+"\n");
    } 
  }
  ::weapon_hit(attacker);
}

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
