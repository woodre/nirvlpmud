#include "../def.h"

object sh;

start_shadow(ob){
 sh=ob;
 shadow(sh, 1);
  call_out("end_shadow", 4 + random(TP->query_guild_rank()));
 }
 
end_shadow(){
  if(environment(sh))
  {
   tell_room(environment(sh),
     MAG+sh->query_name()+" appears to have regained consciousness.\n"+NORM);
   }
  destruct(this_object());
}

short() {
  if(sh->short()) {
    return sh->short() +" "+MAG+" * dazed *"+NORM;
  }
}

int query_block_attack(){
  return 1;
}

move_player(str){
  if(random(4) && !sh->query_ghost())
  tell_object(sh, MAG+"You are dazed!\n"+NORM);
  else { sh->move_player(str); destruct(this_object()); }
}
