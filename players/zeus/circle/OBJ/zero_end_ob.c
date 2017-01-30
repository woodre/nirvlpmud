inherit "/obj/treasure.c";
#define User environment()

reset(arg){
	  if(arg) return;

  set_id("zero_endurance_obj");
  set_short(0);
  set_long(0);
  set_alias(0);
  set_weight(0);
  set_value(0);
  set_heart_beat(1);
  call_out("end", 120 + random(60));
}

okay()
{
  if(!environment()) return;
  
  if(!environment(User))
  {
    destruct(this_object());
    return;
  }
  
  tell_object(User,
    "You feel a bit stronger...\n");
  destruct(this_object());
}

void heart_beat()
{
  if(!environment()) return ;
  
  if(present("circle_object", User))
    present("circle_object", User)->set_endurance(0);
}

get(){ return 0; }

drop(){  return 0; }
