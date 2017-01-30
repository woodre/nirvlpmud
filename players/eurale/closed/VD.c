#include "/players/eurale/closed/ansi.h"
int time;

init_arg(arg) {
  sscanf(arg,"%d",time);
}

reset(arg)  {
  if(arg) return;
/* ld doesn't like callouts in reset in castle preloads -Bp
call_out("timer",1);
*/
}
init() {
  while(remove_call_out("timer") != -1);
  call_out("timer",15);
}

long() {
  write("Spreading crud "+time+"\n"); }

id(str) { return str == "crotchrot"; }

query_real_name() {
  if(time > 27999) return "VENEREAL DISEASE";
  else return; }

query_weight() { return 0; }

query_auto_load() { return "/players/eurale/closed/VD.c:"+time; }

timer() {
if(environment(this_object())) {
  time++;
  if(time == 5000) {  call_out("aids_player",1); return 1; }
  if(time == 11000) { call_out("aids2_player",1); return 1; }
  if(time == 17000) { call_out("aids3_player",1); return 1; }
  if(time == 22000) { call_out("aids4_player",1); return 1; }
  if(time == 25000) { call_out("aids5_player",1); return 1; }
  if(time == 28000) { call_out("aids6_player",1); return 1; }
call_out("timer",5);
  }
return 1; }

aids_player() {
if(!environment(this_object())) return 1;
tell_object(environment(this_object()),BOLD+
  "You break out in a cold sweat for no obvious reason."+NORM+"\n");
environment()->raise_strength(-2);
call_out("timer",1);
return 1;
}

aids2_player() {
if(!environment()) return 1;
tell_object(environment(this_object()),BOLD+
  "Your mouth becomes very dry and you start to sweat."+NORM+"\n");
environment()->raise_strength(-2);
environment()->raise_stamina(-1);
environment()->raise_luck(-2);
call_out("timer",1);
return 1; }

aids3_player() {
if(!environment()) return 1;
tell_object(environment(this_object()),BOLD+
  "You feel kind of dizzy, disoriented and weak."+NORM+"\n");
environment()->raise_strength(-4);
environment()->raise_stamina(-3);
environment()->raise_magic_aptitude(-2);
environment()->raise_luck(-2);
call_out("timer",1);
return 1; }

aids4_player() {
if(!environment()) return 1;
tell_object(environment(this_object()),BOLD+
  "Your breath comes hard and you feel very hot and dry."+NORM+"\n");
environment()->raise_strength(-5);
environment()->raise_stamina(-6);
environment()->raise_magic_aptitude(-5);
environment()->raise_luck(-7);
call_out("timer",1);
return 1; }

aids5_player() {
if(!environment()) return 1;
tell_object(environment(this_object()),BOLD+
  "You suddenly become very nauseous and throw up!"+NORM+"\n");
environment()->raise_strength(-7);
environment()->raise_stamina(-8);
environment()->raise_magic_aptitude(-6);
environment()->raise_luck(-9);
call_out("timer",1);
return 1; }

aids6_player() {
object ob, ob2;
if(!environment()) return 1;
tell_object(environment(this_object()),BOLD+
  "Your knees buckle, you've lost all strength and you tumble to\n"+
  "the ground.  You can feel your life forces ebbing away and you\n"+
  "know that this is the end.....  You pray for forgiveness."+
  NORM+"\n");
ob = clone_object("/obj/monster.c");
ob->set_hp(10000);
ob->set_ac(1000);
ob->set_wc(10);
ob->set_name("Venereal Disease");
move_object(ob, environment(environment(this_object())));
if(ob2 = environment()->query_attack())
{
  ob2->stop_fight();
  environment()->stop_fight();
  environment()->stop_fight();
  ob2->stop_fight();
}
environment(this_object())->attacked_by(ob);
environment(this_object())->hit_player(10000, "other|disease");
destruct(ob);
destruct(this_object());
return 1; }

drop() {
if(environment()->query_ghost()) {
  if(random(100) > 40) destruct(this_object());
  return 1; }
else return 1; }
get()   { return 0; }
can_put_and_get()  { return 0; }
