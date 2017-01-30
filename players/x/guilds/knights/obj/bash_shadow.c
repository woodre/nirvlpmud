#include <ansi.h>

object mob;

void start_bash(object obj, int t){
  mob = obj;
 
  shadow(mob, 1); 
  call_out("end_bash", t);
}

void end_bash(){
  destruct(this_object());
}

string short() {
 return (string)mob->short()+" ("+HIK+"reeling"+NORM+")"; 
}

void long() {
  mob->long();
  
  write(HIK+(string)mob->query_name()
  +" is reeling from a heavy blow.\n"+NORM);
}

int is_bash_reeling(){
  return 1;
}

move_player(){
  tell_room(environment(mob),
    mob->query_name()+
  " tries to move but is reeling from a shield bash!\n");
}

move_object(){
  move_player();
}

run_away(){
  move_player();
}

movement(){
  move_player();
}