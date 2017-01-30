#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "obj/treasure";
 
#define DAMAGE (environment()->query_hp() / 50)
#define DELAY 10
#define LONGEVITY 10

int duration, TOTAL;

id(str) { return str=="happyfamilygoodtime"; }

reset(arg) {
  if(!arg) {
    duration=LONGEVITY;
    call_out("bring_the_hurtin",random(DELAY));
  }
}

init_arg(str) {  sscanf(str,"%d",duration); }

bring_the_hurtin()
{
  object blood;
  if(!environment()) return;
  blood = present("blood_pool", environment(environment()));
  if(EN)
  { 
    tell_room(environment(environment(this_object())),
      "     "+RED+capitalize(ENN)+" bleeds profusely from a large open wound. "+capitalize(ENN)+" looks weaker."+NORM+"\n");
    environment()->add_hit_point(-DAMAGE);
    if(blood)
    {
      blood->increase_size();
    }
    else
    {
      MO(CO("/players/fred/closed/bloodfist/obj/blood_pool.c"), environment(environment()));
    }
    TOTAL += DAMAGE;
    if(TOTAL > 24)
    {
      destruct(TO);
    }
    duration--;
    if(duration <= 0)
    {
      destruct(TO);
    }
    call_out("bring_the_hurtin", random(DELAY));
  }
  return 1; 
}

drop()  { return 1; } 
get()   { return 0; } 

