/* sqrlmod.c: a 'special' squirrel for the occaison */

#define MANAGER "/players/wizardchild/fools/manager.c"

inherit "/players/wizardchild/fools/sqrl2.c";

is_squirrel() { return 1; }
int is_frothing;
status mute;

set_short(s) { short_desc = s; }
delayed_message(string msg,int time) {
  while(remove_call_out("display_message") != -1) ;
  call_out("display_message",time,msg);
}
display_message(s) {
  tell_room(environment(),s);
}
prepare_death() {
  display_message("A squirrel runs off to find a place to die in.\n");
}
prepare_birth() {
  display_message("A squirrel twists and girates momentarily, then produces a cute little\n"+
                  "baby squirrel.\n");
}
is_frothing() { return is_frothing; }
froth() {
  if(is_frothing) return ;
  is_frothing = 1;
  short_desc += " (frothing)";
  display_message("A squirrel starts to froth at the mouth.\n");
  do_froth_messages();
}
do_froth_messages() {
  while(remove_call_out("do_froth_messages") != -1) ;
  if(!is_frothing) return ;
  call_out("do_froth_messages",8+random(15));
  delayed_message(MANAGER->random_froth(),random(10));
}
stop_froth() {
  if(is_frothing) {
    while(remove_call_out("do_froth_messages") != -1) ;
    sscanf(short_desc, "%s (frothing)",short_desc);
    is_frothing = 0;
    display_message("A squirrel appears to stop frothing.\n");
  }
}
heart_beat() {
  if(!test_if_any_here()) { set_heart_beat(0); mute = 1; return ; }
  ::heart_beat();
  if(query_attack())
    MANAGER->squirrel_assault(query_attack());
}
catch_tell(s) {
if(mute) return ;
if((query_attack() && random(20) < 1) || random(20) < 4)
  MANAGER->display_random_msg(random(40),this_object());
}
init() {
  mute = 0;
  while(remove_call_out("idle_death") != -1) ;
  call_out("idle_death",600);
  set_heart_beat(1);
  add_action("try_kill","kill");
}
try_kill(str) {
   if(id(str) && is_frothing) {
write("You go to attack the squirrel, but the thought of getting bitten\nmakes you wet your pants.\n");
    return 1;
  } return 0;
}
idle_death() {
  prepare_death();
  MANAGER->signal_death(this_object());
  destruct(this_object());
}
second_life() { /* called when we die in combat */
  MANAGER->signal_death(this_object());
}
remove_object(caller) {
  if(caller->is_player())
    MANAGER->signal_death(this_object());
}
