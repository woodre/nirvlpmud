#define ROOM environment(environment(this_object()))
#define EN environment(this_object())
int monwc;
reset(arg){
 if(arg)
   return;
 monwc = 0;
 if(!root())
 call_out("gone", 7+random(7));
}
short(){ return; }
long(){ write("A nasty headwound.\n"); return; }
id(str){ return str == "concussion" || str == "concussion_obj"; }
get(){ return 0; }
drop(){ return 1; }
extra_short(){ return "*UNCONSCIOUS*"; }

init(){
 if(EN->query_level() < 99) {
#ifndef __LDMUD__
    add_action("noper"); add_xverb("");
#else
    add_action("noper", "", 3);
#endif
  }
}

noper(){
  tell_object(EN, "You are unconscious.\n");
  return 1;
}

do_conc(){
  if(EN->query_npc() == 1){
  monwc = EN->query_wc();
  EN->set_wc("STUNNED");
  }
  if(EN->query_npc() == 0 || EN->is_player() == 1)
    call_out("conc_check", 3);
  return 1;
}

gone(){
  if(ROOM)
  tell_room(ROOM, capitalize(EN->query_name())+
  " recovers from a nasty concussion.\n");
  tell_object(EN,
  "You recover consciousness.\n"+
  "You have one hell of a headache!\n");
  if(EN->query_npc() == 1) EN->set_wc(monwc);
  destruct(this_object());
  return 1;
}

conc_check(){
  if(EN->query_ghost()){
    gone(); return 1; }
  if(!EN->query_interactive()){
    gone(); return 1; }
  call_out("conc_check", 5);
  return 1;
}
