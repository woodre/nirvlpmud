#include "/players/fred/ansi.h"
object nmy;
int count,time;

reset(arg){
  if(arg) return;

  time = 0;
  count = 20;
  set_heart_beat(1);
}

id(str){ return str == "bf_f_p" || str == "poison"; }

set(x){ nmy = x; }
get(){ return 0; }
drop(){ return 1; }
can_put_and_get(){ return 0; }

void heart_beat(){
  if(!environment()) return;
  if(!living(environment())){ destruct(this_object()); return; }
  if(!nmy) return;
  time++;
  if(time > 5)
  {
    tell_object(nmy, HIG+"You can feel a poison racing through"+
      " your veins...\n"+NORM);
    tell_room(environment(nmy), HIG+nmy->query_name()+
      " is weakened by the poison within "+nmy->query_objective()+".\n"+NORM,
      ({ nmy }));
    nmy->hit_player(3, "other|poison");
    count--;
    time = random(4);
  }
  if(count < 1)
  {
    tell_object(nmy, "The poison works its way out of your system.\n");
    tell_room(environment(nmy), nmy->query_name()+" starts to feel better.\n",
      ({ environment() }));
    destruct(this_object());
  }
}

extra_look(){  if(living(environment()) && (this_player() != environment()))
return HIG+environment()->query_name()+" has a poison racing through "+
environment()->query_objective()+NORM; }

