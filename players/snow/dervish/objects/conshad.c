#include "/players/snow/dervish/def.h"

object victim;
int time;

set_victim(object ob) {
  if(!ob) return;
  victim = ob;
  shadow(victim, 1);
  return 1; }

set_time(num) {
/* This was intended to be heartbeats. Since it is changed to call_out, we must modify for 3 secs per heartbeat. -Snow 7/01 */
  time = 3*num;
  call_out("end_shadow",time); }

stop_con_shadow() {
  shadow(victim, 0);
  destruct(this_object());
  return 1; }

end_shadow() {
  end();
  if(victim)
  shadow(victim,0);
  destruct(this_object());
}

fake_beat() {
  if(!environment()) return;
  if(!random(5)) effect();
  if(!time) {
  end();
  if(victim)
  shadow(victim, 0);
  destruct(this_object()); }
  time --; }

hit_player(int num,string type,int num2,string type2) {
  int total;
  object me;
  me = this_player();
  if(me && me->query_guild_name() != "dervish")
    return victim->hit_player(num);
  total = num;
  total = total * 2;
  if(total > 50) total = 50;
  return victim->hit_player(total, type, num2, type2); }

/* added by illarion 2 dec 2004 so that confuse will worth
  with the new dtype code */
do_damage(int *damarr, string *typearr) {
  int s,d;
  object me;
  me = this_player();
  if(me && me->query_guild_name() != "dervish")
    return victim->do_damage(damarr,typearr);
  s=sizeof(damarr);
  while(s--) {
    damarr[s]*=2;
    if(damarr[s]>50) damarr[s]=50;
  }
  return victim->do_damage(damarr,typearr);
}
   
short() {
  string sh;
  sh=victim->short();
  if(sh) return sh + " "+BOLD+RED+"(Confused)"+OFF+OFF; }

is_confused() { return 1; }

effect() {
  if(victim && environment(victim)) {
  tell_room(environment(victim),
    victim->query_name()+" stumbles about in a whirlwind of sand.\n");
  return 1; }
  return; }

end() {
  if(victim && environment(victim)) {
  tell_room(environment(victim),
    victim->query_name()+" blinks as the sand dissipates.\n");
  return 1; }
  return; }
