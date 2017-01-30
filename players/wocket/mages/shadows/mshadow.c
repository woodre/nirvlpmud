/* 
  Mage Shadow
*/

#include "../defs.h"
  object mage;

start_shadow(obj){
  mage = obj;
  shadow(mage,1);
  return 1;
}

stop_shadow(ob){
  shadow(mage,0);
  destruct(this_object());
  return1; 
}

quit(){
  shadow(player,0);
  mage->quit();
  return 1;
}