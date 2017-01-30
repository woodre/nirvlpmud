#define ROOM environment(environment(this_object()))
#define EN environment(this_object())

int monwc;

reset(arg){
 if(arg)
   return;
 monwc = 0;
 call_out("gone", 5+random(15));
}

short(){ return; }
long(){ return; }
id(str){ return str == "fear_obj" || str == "fear"; }
get(){ return 0; }
drop(){ return 1; }
extra_short(){ return "<COWERING>"; }

init(){
#ifndef __LDMUD__
  add_action("noper"); add_xverb("");
#else
  add_action("noper", "", 3);
#endif
}

noper(){
  tell_object(EN, "You cower helplessly on the floor!\n");
  return 1;
}

do_fear(){
  if(EN->query_npc() == 1){
    monwc = EN->query_wc();
    EN->set_wc("STUNNED");
  }
  if(EN->query_npc() == 0 || EN->is_player() == 1)
    call_out("conc_check", 3);
  return 1;
}

gone(){
  tell_room(ROOM, capitalize(EN->query_name())+
  " recovers from the fear spell.\n");
  tell_object(EN,
  "You recover from the fear spell.\n");
  if(EN->query_npc() == 1) EN->set_wc(monwc);
  destruct(this_object());
  return 1;
}

conc_check(){
  if(EN->query_ghost()){
    gone(); return 1;
  }
  if(!EN->query_interactive()){
    gone(); return 1;
  }
  call_out("conc_check", 5);
  return 1;
}
