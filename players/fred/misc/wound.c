#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "obj/treasure";
 
#define DAMAGE (10+random(5))
#define DELAY 8
#define LONGEVITY 8

int duration;

id(str) { return str=="happyfamilygoodtime"; }

reset(arg) {
  if(!arg) {
    duration=LONGEVITY;
    call_out("bring_the_hurtin",DELAY);
  }
}

init_arg(str) {  sscanf(str,"%d",duration); }

bring_the_hurtin() {
  if(EN) { 
    tell_room(environment(environment(this_object())),
      "     "+RED+capitalize(ENN)+" bleeds profusely from a large open wound. "+capitalize(ENN)+" looks weaker."+NORM+"\n");
     if(DAMAGE > EN->query_hp()){ return 1; } 
     if(EN->query_ghost()) { return destruct(this_object()); }
     call_other(environment(),"heal_self",-DAMAGE);
    duration--;
    if(duration <= 0) {
      destruct(TO);
    }
    call_out("bring_the_hurtin",DELAY);
  }
  return 1; 
}

drop()  { return 1; } 
get()   { return 0; } 

