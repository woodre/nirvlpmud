
string room_token;

inherit "/room/room";

void reset(status arg){
  ::reset(arg);
  if(arg) return;
}

string query_room_token() {
  return room_token;
}

void set_room_token(string rt) {
  room_token=rt;
}
