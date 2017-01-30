inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define EQN environment()->query_name()
#define QHP environment()->query_hp()
#define QMHP environment()->query_mhp()
#define AQN environment()->query_attack()->query_name()
#define AHP environment()->query_attack()->query_hp()
#define AMHP environment()->query_attack()->query_mhp()

reset(arg){
  set_id("monitor");
  set_short(BLU+"Battle Monitor"+NORM);
  set_long(0);
  set_alias("battle");
  set_weight(0);
  set_value(0);
  set_heart_beat(1);
}

drop(){  return 0; }
prevent_insert(){ return 1; }

void heart_beat(){
  if(!environment()){
     destruct(this_object());
         return;
  }
  if(!environment()->query_attack()){
         destruct(this_object());
         return;
  }
  TR(environment(ENV), HIC+EQN+":\t  "+NORM+QHP+"/"+QMHP+"\n"+
                           HIM+AQN+":\t  "+NORM+AHP+"/"+AMHP+"\n");
}
