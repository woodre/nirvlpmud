#include "/players/boltar/things/esc.h"
int room_num,lastv;

short() { 
 if(environment(this_object()))
   call_other("/players/boltar/casino/front_desk", "fix_book_name",room_num, environment(this_object())->query_real_name());
return "A hotel key card"; }

long() {
   write("A key card with printing reading:\n");
   write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[31m"+esc+"[40m Casa de Nirvana Hotel and Casino"+esc+"[0m");
   write("\nRoom Number "+room_num+"\n");
   return 1;
}

query_value() { return 0; }
query_weight() { return 0; }

id(str) { 
return str == "key" || str == "key card" || str == "card" || str == "CasaNirvanaKey" || str == "ND";
}

get() { return 1;}

set_room_num(arg) { room_num = arg; }
set_lastv(arg) { lastv = arg; }
query_room_num() { return room_num; }

drop() { return 1; }

query_auto_load() {
  return "players/boltar/casino/key:"+room_num;
}

reset(arg) {
  string occvac;
  int verif;
  if (arg) return;
  return;
}

check_expired() {
  string occvac,whoseroom;
  int verif;
  if(room_num) {
    occvac = call_other("players/boltar/casino/front_desk","query_room_status",room_num);
    if (occvac == "v") destruct(this_object());
  if(this_object())
  if(environment(this_object()))
    whoseroom =  call_other("/players/boltar/casino/front_desk","fix_book_name",room_num,environment(this_object())->query_real_name());
  if(whoseroom == "DESTROY") destruct(this_object());
/*
    verif = call_other("players/boltar/casino/front_desk","query_last_visit",room_num);
    if (lastv)
      if (verif == lastv) destruct(this_object());
*/
  }
  return;
}

init_arg(arg) {
  if(arg){
   sscanf(arg,"%d",room_num);
  }
  check_expired();
}
query_room_number() { return room_num; }
init() {
 check_expired();
}
