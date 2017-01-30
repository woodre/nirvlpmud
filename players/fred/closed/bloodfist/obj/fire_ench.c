#include "/players/fred/ansi.h"
object nmy;
int a;
string m;

reset(arg){
  if(arg) return;

  set_heart_beat(1);
}

id(str){ return str == "bf_f_o"; }

set(x){ nmy = x; }
get(){ return 0; }
drop(){ return 1; }
can_put_and_get(){ return 0; }

void heart_beat(){
  if(!environment()) return;
  if(!living(environment())){ destruct(this_object()); return; }
  if(!nmy) return;
  a = random(6);
  switch(a){
    case 0:
      m = "Flames dance across "+nmy->query_name()+"'s body!\n";
      break;
    case 1:
      m = "Flames scorch "+nmy->query_name()+"'s flesh!\n";
      break;
    case 2:
      m = nmy->query_name()+" writhes as the flames burn "+
        nmy->query_objective()+"!\n";
      break;
    case 3:
      m = "Billowing flames rise up from "+nmy->query_name()+"!\n";
      break;
    case 4..5:
      m = 0;
      break;
  }
  if(m)
  {
    tell_room(environment(nmy), RED+m+NORM);
    nmy->hit_player(4, "other|fire");
  }
  else if(!m && !random(2)){
    tell_room(environment(nmy), BOLD+BLK+
      "The flames die down from around "+nmy->query_name()+"...\n"+NORM);
    destruct(this_object());
  }
}

