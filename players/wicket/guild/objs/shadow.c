#include <ansi.h>
#include "../defs.h"

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
   
short() {
  string sh;
  sh=victim->short();
  if(sh) return sh + " ("+BOLD+"Encased"+NORM+" in "+CYN+"Ice"+NORM+")"+NORM; }

is_sprayed() { return 1; }

effect() {
  if(victim && environment(victim)) {
  tell_room(environment(victim),
    victim->query_name()+" struggles to breathe in the icy prison!\n");
  return 1; }
  return; }

end() {
  if(victim && environment(victim)) {
  tell_room(environment(victim),
    CYN+victim->query_name()+" breaks out of the icy prison!\n"+NORM);
  return 1; }
  return; }
