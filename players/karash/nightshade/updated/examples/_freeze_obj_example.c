#include "/players/fred/mages/defs.h"

object frozen;
int time;

do_shadow(object ob) {
  if(!ob) return;
  frozen = ob;
  shadow(frozen, 1);
  return 1; }

set_time(num) {
  time = 8*num;
  call_out("stop_shad",time); }

stop_shad(){
  done();
  if(frozen)
  shadow(frozen,0);
  destruct(TO);
}

hit_player(int num) {
  int amount;
  object me;
  me = this_player();
  if(me && me->query_guild_name() != "black circle")
    return frozen->hit_player(num);
  amount = num;
  amount = (amount*10)/8;
  if(amount > 50) amount = 50;
  return frozen->hit_player(amount); }
    
short() {
 return frozen->short()+","+BOLD+BLU+" **fRoZEn**"+NORM;
}

brave() { return 1; }

done() {
  if(frozen && ENV(frozen)) {
  tell_room(ENV(frozen),
    frozen->query_name()+" regains focus as the ice melts away.\n");
  return 1; }
  return; }

move_player(){
  tell_room(ENV(frozen),
  frozen->query_name()+" tries to move but is frozen...\n");}

move_object(){
  tell_room(ENV(frozen),
  frozen->query_name()+" tries to move but is frozen...\n");}

run_away(){
  tell_room(ENV(frozen),
  frozen->query_name()+" tries to run but is frozen...\n");}

movement(){
  tell_room(ENV(frozen),
  frozen->query_name()+" tries to move but is frozen...\n");}
