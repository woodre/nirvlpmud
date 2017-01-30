#include "/players/mythos/bounty/spells/def.h"
string slayd;
string formd;
string bstyles, cstyles;
string slay_bstyles, slay_cstyles;
int poison,drug;

set_slay(str) { slayd = str; }
set_form(str) { formd = str; }

set_poison(n) { poison = n; }
set_drug(n) { drug = n; }

long() { ::long();
         if(poison) write(BOLD+"Poisoned  "+NORM);
         if(drug) write(BLU+"Drug  "+NORM);
         write("\n");
       }
       
short() { string h;
          h = 0;
          if(poison) h = BOLD+"P "+NORM;
          if(drug) { if(!h) h = BLU+"D "+NORM; else h += BLU+"D "+NORM; }
          if(!h) h = short(); else h += ::short();
          return h+RED+" ["+slayd+" slayer]"+NORM; }

query_bounty_weapon() { return 1; }

reset(arg) {
    ::reset(arg);
    if (arg) return;
    poison = drug = 0;
    bstyles = allocate(10);
    cstyles = allocate(10);
    slay_bstyles = allocate(5);
    slay_cstyles = allocate(5);
    
}

weapon_hit(attacker) {
int meows;
string meowm;
object shadesm;
  if(random(3) == 0 && bbG) {
    meows = random(10);
    if(formd == "tech") meowm = cstyles[meows];
    else meowm = bstyles[meows];
    tell_room(etP,meowm+NORM+"\n");
    if(poison && random(3) == 0) poison_targ(attacker);
    if(drug && random(3) == 0) drug_targ(attacker);
    if(atT->id(slayd) && random(60) < bbL) {
      meows = random(5);
      if(formd == "tech") meowm = slay_cstyles[meows];
      else meowm = slay_bstyles[meows];
      if(tpsP > 40 && random(3) == 0) tpR->shock_object(atT);
      else atT->heal_self(-random(bbL/2));
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
    counter = clone_object("/players/mythos/bounty/spells/poison.c");
    counter->set_level(bbL);
    move_object(counter,targ);
  } 
}

drug_targ(ob) {
object targ,counter;
string type;
  switch(random(3)) {
    case 0: type = ""; break;
    case 1: type = ""; break;
    case 2: type = ""; break;
  }
  targ = ob;
  if(!targ) return 0;
  counter = present(type+" mbdrug",targ);
  if(counter) {
    counter->set_level(bbL);
    if(counter->query_time() < counter->query_mtime()) 
      counter->set_time(counter->query_mtime());
  } else {
    counter = clone_object("/players/mythos/bounty/spells/drug.c");
    counter->set_level(bbL);
    counter->set_type(type);
    move_object(counter,targ);
  } 
}