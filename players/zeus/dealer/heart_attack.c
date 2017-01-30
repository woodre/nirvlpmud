inherit "/obj/treasure.c";
object v;

reset(arg){
          if(arg) return;

  set_id("zeus_heart_attack");
  set_short(0);
  set_long(0);
  set_weight(0);
  set_heart_beat(1);
  call_out("okay", 11);
}

okay(){
  if(v) tell_object(v, "You regain control of your body...\n");
  destruct(this_object());
}

void init(){
#ifndef __LDMUD__
  add_action("ouch_it_hurts"); add_xverb("");
#else
  add_action("ouch_it_hurts", "", 3);
#endif
}

ouch_it_hurts(){
  if(v) tell_object(v,
  "You are wracked by pain as you try to move.\n"+
  "You realize you have no control over your movements.\n");
  return 1;
}

void heart_beat(){
  if(!environment()) return; if(!v) return;
  if(!random(3))
    tell_object(v, "You slam about as pain consumes you.\n");
}

setv(x){ x = v; }
get(){ return 0; }
drop(){  return 0; }
