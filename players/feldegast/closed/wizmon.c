#define OWNER environment(this_object())
#define ATTACKER target->query_attack()
object target;
int time, t;

display() {
  if(!target)
    tell_object(OWNER,"=< NONE >=\n");
  else {
    if(target) {
      tell_object(OWNER,"=< "+capitalize(target->query_name())+" HP: "+
          target->query_hp());
      if (target->is_player()) {
        tell_object(OWNER,"/"+target->query_mhp());
        tell_object(OWNER," SP: "+target->query_spell_point());
        tell_object(OWNER,"/"+target->query_msp());
      }
      tell_object(OWNER," >=");   
    }
    if(ATTACKER) {
      tell_object(OWNER,"*< "+capitalize(ATTACKER->query_name())+" HP: "+ATTACKER->query_hp()+" >*");
    }
    tell_object(OWNER,"\n");
  }
} 


heart_beat() {
  if(time==0) display();
  time++;
  if(time==t) time=0;
}

init() {
  add_action("set","set");
  add_action("start","start");
  add_action("stop","stop");
  add_action("span","span");
  t=1;
}

short() {
  return "Wiz Monitor";
}

long() {
  write("This is a wiz toy designed to monitor living objects from afar.\n"+
        "'set <living>' to monitor a monster or player.\n"
  );
}

id(str) {
  return str=="monitor"|| str=="wiztoy";
}
get() {
  return 1;
}
query_value() {
  return 10;
}
query_weight() {
  return 0;
}

start() {
  if (!set_heart_beat(1)) write("Error!\n");
  write("Monitor started.\n");
  return 1;
}  

stop() {
  if (!set_heart_beat(0)) write("Error?\n");
  write("Monitor stopped.\n");
  return 1;
}
span(arg) {
  if(!arg) {
    write("You must use an integer argument.\n");
    return 1;
  }
  sscanf(arg,"%d",t);
  write("Time span set to "+t+".\n");
  return 1;
}
  
set(str) {
  if (!str) {
    target=0;
    write("Monitor cleared.\n");
    return 1;
  }
  if (target=find_living(str)) {
    write("Target acquired.\n");
    write(target->query_name()+" is now set to monitor 1.\n");
    return 1;
  }
  write("Target not found.\n");
  return 1;
}
