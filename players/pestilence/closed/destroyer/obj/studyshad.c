#include "/players/pestilence/define.h"

object victim;
int time;

set_victim(object ob) {
  if(!ob) return;
  victim = ob;
  shadow(victim, 1);
  return 1; }

set_time(num) {
  time = 3*num;
  call_out("end_shadow",time); }

stop_con_shadow() {
  shadow(victim, 0);
  destruct(this_object());
  return 1; }

end_shadow() {
  end();
  shadow(victim,0);
  destruct(this_object());
}

fake_beat() {
  if(!environment()) return;
/*
  if(!random(5)) effect();
*/
  if(!time) {
  end();
  shadow(victim, 0);
  destruct(this_object()); }
  time --; }

hit_player(int num) {
  int total;
  object me;
  me = this_player();
  if(me && me->query_guild_name() != ">A.o.P<")
    return victim->hit_player(num);
  total = num;
   total = total * 2;
  if(total > 50) total = 50;
  return victim->hit_player(total); }
    
short() {
  string sh;
  sh=victim->short();
  if(sh) return sh + " "+YEL+">studied<"+NORM; }

is_studied() { return 1; }

effect() {
  if(victim && environment(victim)) {
  tell_room(environment(victim),
    victim->query_name()+" stumbles about in a whirlwind of sand.\n");
  return 1; }
  return; }


end() {
  if(victim && environment(victim)) {
  tell_room(environment(victim),
  HIY+victim->query_name()+" begins to fight slightly different, modifying its weaknesses"+NORM+".\n");
  return 1; }
  return; }
