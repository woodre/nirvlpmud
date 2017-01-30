#include <ansi.h>
#define ENV environment(this_object())

int breath;
int do_count;

reset(arg){
  if(arg) return;
  breath = 0;
  do_count = 0;
  call_out("breathe", 10);
}

id(str) {
  return str == "hold_breath";
}

long(){
  return;
}

short(){
  return;
}

get() {
  return 1;
}

drop() {
  return 1;
}

query_weight() {
  return 0;
}

query_value() {
  return 0;
}

query_save_flag() {
  return 1;
}

add_breath(i) { breath += i; }
query_breath() { return breath; }

breathe() {
  if(!ENV) {
    destruct(this_object());
    return 1;
  }
  if(!living(ENV)) {
    destruct(this_object());
    return 1;
  }
  if(ENV->query_ghost()) {
    destruct(this_object());
    return 1;
  }
  if(!environment(ENV)->query_underwater()) {
    if(!present("water_breath", ENV)) {
       tell_object(ENV,
      "Your lungs gratefully gulp in the fresh air!\n");
    }
    destruct(this_object());
    return 1;
  }
  if(present("water_breath", ENV)) {
    call_out("breathe", 10);
    return 1;
  }
  if(do_count < 4) {
    do_count++;
    call_out("breathe", 3);
    return 1;
  }

  breath--;
  do_count = 0;

  if(breath==7)  tell_object(ENV, YEL+
     "You are holding your breath while you swim underwater.\n"+NORM);
  if(breath==4)  tell_object(ENV, YEL+
     "You are beginning to get short on air.\n"+NORM);
  if(breath==2) tell_object(ENV, YEL+
     "Your chest begins to ache from lack of air.\n"+NORM);
  if(breath==1) tell_object(ENV, YEL+
     "You had better get some air soon!\n"+NORM);
  if(breath==0) tell_object(ENV, YEL+
     "Your lungs are burning with the need for air!\n"+NORM);

  if(breath < 0) {
    int dmg, i;

    i = random(5);
    if(i==0) tell_object(ENV, YEL+"~ "+HIR+
       "Your eyes are bulging.\n"+NORM);
    if(i==1) tell_object(ENV, YEL+"~ "+HIR+
       "Your lungs feel like they are on fire!\n"+NORM);
    if(i==2) tell_object(ENV, YEL+"~ "+HIR+
       "Your body screams for air!\n"+NORM);
    if(i==3) tell_object(ENV, YEL+"~ "+HIR+
       "Your chest feels like it is going to explode!\n"+NORM);
    if(i==4) tell_object(ENV, YEL+"~ "+HIR+
       "Your must get some air soon!\n"+NORM);

    dmg = breath < 0 ? -breath : breath;

    ENV->hit_player(dmg);
  }

  if(breath < -10) {
    if(!ENV->is_player()) {
      tell_room(environment(ENV), YEL+"~~~ "+HIR+
      capitalize(ENV->query_name())+" suffocates and DIES!!!\n"+NORM);
      ENV->hit_player(10000);
      destruct(this_object());
      return 1;
    }
    else if(random(50) == 13) {
      tell_object(ENV, YEL+"\n~~~ "+HIR+
      "YOU SUFFOCATE TO DEATH!!!\n\n"+NORM);
      tell_room(environment(ENV), YEL+"~~~ "+HIR+
      capitalize(ENV->query_name())+" suffocates and DIES!!!\n"+NORM);
      ENV->hit_player(10000);
      destruct(this_object());
      return 1;
    }
  }

  call_out("breathe", 3);
  return 1;
}

