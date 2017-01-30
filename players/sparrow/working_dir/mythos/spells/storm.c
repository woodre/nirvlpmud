#include "/players/mythos/closed/guild/def.h"
int time, check, growth;
int gt, perm, ti, echo;

id(str) {return str == "storm_ob" || str == "weather"; }

get() { return 0;}
drop() { return 1;}

set_time(n) { time = n;}
set_pcheck(b) { check = b;}
set_growth(g) { growth = g; gt = g;}
query_perm() { return perm;}

reset(arg) {
  if(arg) return;
  perm = 0;
  echo = 2;
  call_out("storm",3);
}

storm() {
int n;
object here;
if(!ep) return 1;
here = all_inventory(ep);
  for(n = 0; n<sizeof(here); n++) {
    if(here[n] != this_object() && here[n]->id("weather")) {
        destruct(this_object());
        return 1;}
      perm = 1; 
    }
  for(n = 0; n<sizeof(here); n++) {
    if(living(here[n]) && !(here[n]->id("messenger")) && 
        (here[n]->query_npc() || check != 0) &&
      random(10) == 0) {
      here[n]->heal_self(-random(50));
      tell_room(ep,here[n]->short()+
               " is struck by a "+BLU+" BOLT of LIGHTNING!\n"+NORM);
      }
  }
  if(echo < 1) {
  switch(random(4)) {
  case 0 : tell_room(ep,"The storm overhead grumbles and roars!\n"); break;
  case 1 : tell_room(ep,"Lightning flashes!\n"); break;
  case 2 : tell_room(ep,"The strong wind knocks you to the ground!\n"); break;
  case 3 : tell_room(ep,"FEAR overcomes you as you feel the storm's power!\n"); break;
  }
  echo = random(8);
  }
  else { echo = echo - 1;}
  if(gt < 1) { 
    grow();
    gt = growth;
  }
  else { gt = gt - 1; }
  time = time - 1;
  if(time < 0) { 
  tell_room(ep,"The storm dissipates....\n");
   destruct(this_object());
   return 1;}
  call_out("storm",3);
return 1;}

grow() {
int h;
object seed;
string dire;
if(!ep) return 1;
  dire = ep->query_dest_dir();
  if(dire) {
  h = 1;
  while(h < sizeof(dire)) {
  seed = clone_object("/players/mythos/closed/guild/spells/storm.c");
  seed->set_pcheck(check);
  seed->set_time(time - 1);
  seed->set_growth(6);
  move_object(seed,dire[h-1]);
  h += 2;
  }
  tell_room(ep,"The storm grows and expands!\n");
}
}

query_shatter_proof() { return 1;} 
