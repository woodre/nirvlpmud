#include "/players/boltar/things/esc.h"
int room_num,lastv;

short() { return "A motel key"; }

long() {
   write("A worn motel room key with key chain reading:\n");
   write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[31m"+esc+"[40m One Night Stand Motel"+esc+"[0m");
   write("\nRoom Number "+room_num+"\n");
   return 1;
}

query_value() { return 0; }
query_weight() { return 0; }

id(str) { 
return str == "key" || str == "motel key" || str == "room key" || str == "MotelKey" || str == "ND";
}

get() { return 1;}

set_room_num(arg) { room_num = arg; }
set_lastv(arg) { lastv = arg; }
query_room_num() { return room_num; }

drop() { return 1; }


query_auto_load() {
  return "players/boltar/motel/key:"+room_num;
}

reset(arg) {
  string occvac;
  int verif;
  if (arg) return;
  if(room_num && this_player()) {
    occvac = call_other("players/boltar/motel/front_desk",
             "query_guest_name",room_num);
    if(occvac != this_player()->query_real_name()) destruct(this_object());
  }
  return;
}

init_arg(arg) {
  if(arg){
   sscanf(arg,"%d",room_num);
  }
  if(this_player())
  if(call_other("/players/boltar/motel/front_desk", "query_guest_name", 
     room_num) != this_player()->query_real_name())
     destruct(this_object());
}
query_room_number() { return room_num; }
query_save_flag() { return 1; }
