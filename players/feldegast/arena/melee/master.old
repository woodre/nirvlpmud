#include "def.h"
string *room_list;
int tourney;

void reset(int arg) {
  if(arg) return;
  room_list=ROOMS;
}

string *query_rooms() {
  return room_list;
}

void add_room(string str) {
  room_list+=({ str });
}

void del_room(string str) {
  room_list-=({ str });
}

int query_tourney() {
  return tourney;
}

void set_tourney(int arg) {
  tourney=arg;
}
