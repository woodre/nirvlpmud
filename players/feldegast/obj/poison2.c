/* This is the poison for eating waterthorn */
#define DAMAGE (15+random(20))
#define DELAY 7+random(10)
#define DURATION 5+random(7)

inherit "obj/treasure";

int duration;
int damage;

reset(arg)  {
  if(arg) return;
  set_id("poison");
  set_alias("poison2");
  set_weight(0);
  set_value(0);
/* ld doesn't like this in castle preloads. -Bp
  call_out("poison_player",12);
*/
  duration=DURATION;
  damage=DAMAGE;
}

init() {
  while(remove_call_out("poison_player") != -1);
  call_out("poison_player",15);
}

query_auto_load() { return "/players/feldegast/obj/poison2.c:"+duration; }

init_arg(str) { duration=atoi(str); }

random_emote() {
  string emote;
  switch(random(6)) {
    case 0: emote="You feel VERY ill.\n";
            break;
    case 1: emote="Your limbs feel numb.\n";
            break;
    case 2: emote="You feel your life swiftly draining away.\n";
            break;
    case 3: emote="Your vision begins to fade.\n";
            break;
    case 4: emote="You fall to the floor and vomit.\n";
            break;
    case 5: emote="You feel sick.\n";
            break;
    case 6: emote="You think you're about to die.\n";
            break;
    default: emote="You feel ill.\n";
              break;
  }
  return emote;
}

poison_player() {
  if(environment(this_object())) { 
    tell_object(environment(this_object()),random_emote());
    tell_room(environment(environment()),environment()->query_name()+" looks ill.\n",({ environment() }));
    environment(this_object())->do_damage( ({ damage }), ({ "other|poison" }) );
    duration--;
    if(duration > 0)
      call_out("poison_player",DELAY);
    else {
   if(environment())
      tell_object(environment(),"You feel a little bit better.\n");
      destruct(this_object());
    }
  }
  return 1; 
}

get() { return 0; }

extra_look() {
  return environment()->query_name()+" looks pale and sickly";
}

drop() {
  if(environment()->is_dieing()) destruct(this_object());
  else return 1;
}

set_damage(x) { damage=x; }
set_duration(x) { duration=x; }
