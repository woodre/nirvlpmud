#include <ansi.h>

int charges;

void reset(int x) {
  if(x) return;
  charges = 20;
  if(!root()) 
    set_heart_beat(1);
}

int get(){ return 1; }
int drop(){
  return 1;
}

id(string str){
  return (str=="fear_liath_more");
}

void heart_beat(){
  object atk, room;
  if(!(room = environment(environment())))
  {
    return;
  }
  if((atk = (object)environment()->query_attack()) && present(atk, room)){
    if(!random(4)){
      tell_object(atk, "You feel a "+HIR+"sharp pain"+NORM+" in your head!\n");
      if(room = environment(environment())){
        tell_room(room, (string)atk->query_name()+" recoils in pain and horror from some "+
        "imaginary agony.\n");
        atk->hit_player(50+random(50), "other|mental");
        charges --;
        if(!charges) {
          tell_object(environment(),
            "The powers of "+HIK+"Fear Liath More"+NORM+" drain from your body.\n");
           destruct(this_object());
        }
      }
    }
  }
}
        
