inherit "obj/treasure";

int duration;
int damage;

reset(arg)  {
  if(arg) return;
  set_id("disease");
  set_alias("poison");
  set_weight(0);
  set_value(0);
  call_out("poison",12);
}

query_auto_load() { 
  return "/players/sparrow/closed/bwtProject/obj/poison.c:"+duration; 
}

init_arg(str) { duration=atoi(str); }


void
poison() {
  if(environment()){ 
    tell_object(environment(),"You feel very ill.\n");
    tell_room(environment(environment()),environment()->query_name()+" looks ill.\n",({ environment() }));
    environment(this_object())->do_damage( ({ damage }), ({ "other|poison" }) );
    duration--;
    if(duration > 0)
      call_out("poison", random(7) + 5);
    else {
      tell_object(environment(),"You feel a little bit better.\n");
      destruct(this_object());
    }
  }
  return; 
}

get() { return 0; }

drop() {
  if(environment()->is_dieing()) destruct(this_object());
  else return 1;
}

set_damage(x) { damage=x; }
set_duration(x) { duration=x; }