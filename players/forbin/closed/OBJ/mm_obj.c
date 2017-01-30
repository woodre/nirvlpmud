#include "/players/forbin/define.h"

object Target;
string Msg;
int Strengthen;

reset(arg){
  if(arg) return;

  set_heart_beat(1);
}

id(string str) { return str == "mm_obj"; }

void set(object who) { Target = who; }

void strengthen(int num) { Strengthen = num; }

int get() { return 0; }

int drop() { return 1; }

int can_put_and_get() { return 0; }

void heart_beat() {
  if(!environment()) return;
  if(!living(environment())) { destruct(this_object()); return; }
  if(!Target) return;
  if(!Strengthen)
    switch(random(8)) {
      case 0:
        Msg = "Flames dance across "+Target->query_name()+"'s body!\n";
        break;
      case 1:
        Msg = "Flames scorch "+Target->query_name()+"'s flesh!\n";
        break;
      case 2:
        Msg = Target->query_name()+" writhes as the flames burn "+
          Target->query_objective()+"!\n";
        break;
      case 3:
        Msg = "Billowing flames rise up from "+Target->query_name()+"!\n";
        break;
      case 4:
        Msg = "Billowing flames rise up from "+Target->query_name()+"!\n";
        break;
      case 5..7:
        Msg = 0;
        break;
    }
  else {
    Msg = "Magial energy flashes around "+Target->query_name()+"'s body.\n";
    if(Strengthen) Strengthen--;
  }
  if(Msg) {
    tell_room(environment(Target), 
      (random(2) ? HIC+Msg+NORM : HIW+Msg+NORM));
    Target->hit_player(3, "magical");
    Target->hit_player(3, "other|mental");    
  }
  else if(!Msg && !random(3)) {
    tell_room(environment(Target), (random(2) ? HIC : HIW)+
      "The air around "+Target->query_name()+" hisses as the magical field fades...\n"+NORM);
    destruct(this_object());
  }
}

