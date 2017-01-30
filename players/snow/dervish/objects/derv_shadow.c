#include "/players/fred/defs.h"
object me, shad;

set_derv_shad(object obj){
  me = obj;
  shadow(me, 1);
}

query_derv_shad(){ return 1; }

stop_derv_shad(){
  destruct(TO);
  return 1;
}

add_exp(amt){
  object gob;
  int num, split;
  if(TP){
    if(TP->is_player()){
      gob = present("dervish_tattoo", me);
        if(!gob){
          destruct(TO);
          return;
          }
        }
      }
  if(gob->query_mystic_exp() > 2000000){
    me->add_exp(amt);
    } 
  num = gob->query_mystic_percent();
  num = amt * (num/100);
  gob->add_mystic_exp(num);
  me->add_exp((amt-num));
}
