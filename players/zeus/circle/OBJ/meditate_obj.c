inherit "/obj/treasure.c";
#define User environment()

reset(arg){
	  if(arg) return;

  set_id("meditate_obj");
  set_short(0);
  set_long(0);
  set_alias(0);
  set_weight(0);
  set_value(0);
  set_heart_beat(1);
  call_out("okay", 5+random(4));
}

okay(){
  if(!environment()) return;
  if(!environment(User))
  {
    destruct(this_object());
    return;
  }
  tell_object(User,
    "You slowly rise...\n");
  if(!random(10))
    tell_object(User,
    "You can feel the power of the shadows within you.\n");
  tell_room(environment(User),
    User->query_name()+" slowly rises...\n", ({ User }));
  destruct(this_object());
}

void init(){  
#ifndef __LDMUD__
  add_action("med"); add_xverb("");
#else
  add_action("med", "", 3);
#endif
}

med(string str){
  if(str != "quit" && str != "sc" && str != "mon")
  {
    tell_object(User,
      "You are meditating... be at peace.\n");
    return 1;
  }
}

void heart_beat(){
  if(!environment()) return ;
  if(present("circle_object", User))
    present("circle_object", User)->add_endurance(6);
}

get(){ return 0; }
drop(){  return 0; }
