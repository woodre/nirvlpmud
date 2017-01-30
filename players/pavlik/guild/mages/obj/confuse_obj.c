#define ROOM environment(environment(this_object()))
#define EN environment(this_object())
int monac;

reset(arg){
 if(arg||root())
   return;
}
short(){ return; }
long(){ write("a mages confuse_obj.\n"); return; }
id(str){ return str == "confuse_obj"; }
get(){ return 0; }
drop(){ return 1; }

do_confuse(){
  if(!EN || !living(EN)){
    destruct(this_object());
    return 1;
    }
  monac = EN->query_ac();
  if(monac < 2)
    EN->set_ac(1);
  else
    EN->set_ac(monac - 3);
  call_out("rid_this", 140);
  return 1;
}

rid_this(){
  if(!living(EN)){
    destruct(this_object());
    return 1;
    }
  tell_room(ROOM, capitalize(EN->query_name())+
  " is no longer confused.\n");
  EN->set_ac(monac);
  destruct(this_object());
  return 1;
}
