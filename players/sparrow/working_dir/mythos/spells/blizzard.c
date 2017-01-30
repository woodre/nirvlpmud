#include "/players/mythos/closed/guild/def.h"
int time, check, growth;
int gt, perm, ti, echo;

id(str) {return str == "blizzard" || str == "weather"; }

short() { if(!present("finder",tp)) {
          write("You can not enter the blizzard nor can you find your way!\n"+
                "You are lost!\n"); 
          move_object(tp,"/players/mythos/closed/guild/spells/eye.c");
          return 1; }
        }

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
here = all_inventory(ep);
  for(n = 0; n<sizeof(here); n++) {
    if(here[n] != this_object() && here[n]->id("weather")) {
        destruct(this_object());
        return 1;}
    for(n = 0; n <sizeof(here); n++) {
    if(!present("finder",here[n])) {
      move_object(clone_object("/players/mythos/closed/guild/spells/find.c"),here[n]);
      } }
      perm = 1; 
    } 
  for(n = 0; n<sizeof(here); n++) {
    if(living(here[n]) && !(here[n]->id("messenger")) &&
      (here[n]->query_npc() || check != 0) &&
      random(6) == 0) {
      here[n]->heal_self(-random(5));
      tell_object(here[n],"The wind blows- ice and COLD blast into you-\n"+
                          "freezing you to the bone!\n");
      tell_room(ep,
      "The wind smashes "+capitalize(here[n]->query_name())+" to the ground!\n");
      }
    if(!present("finder",here[n])) {
      tell_object(here[n],"You are lost!\n");
      move_object(here[n],"/players/mythos/closed/guild/spells/eye.c");
      }
  }
  if(echo < 1) {
  switch(random(4)) {
  case 0 : tell_room(ep,"The wind blows- chilling all.\n"); break;
  case 1 : tell_room(ep,"Nothing can be seen but snow and ice....\n"); break;
  case 2 : tell_room(ep,"The strong wind knocks you to the ground!\n"); break;
  case 3 : tell_room(ep,"Howling winds and flying ice cloud your vision!\n"); break;
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
  dire = ep->query_dest_dir();
  if(dire) {
  h = 1;
  while(h < sizeof(dire)) {
  seed = clone_object("/players/mythos/closed/guild/spells/blizzard.c");
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
