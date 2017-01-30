#include "def.h"

inherit AROOM;

string current_room;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=CYN+"Airborne"+NORM;
  long_desc=0;
  current_room="m11";
  items=({
    "ground","You see the ground far beneath you",
  });
}
long(str) {
  write("You are being whirled about inside a tornado!  Beneath you you see:\n");
  view_room(PATH+current_room);
}
void init() {
  ::init();
  call_out("twist",4+random(5));
  call_out("release",5+random(40),this_player());
}

void twist() {  
  current_room=(string)((mixed)MASTER->query_rooms())[random(sizeof((string *)MASTER->query_rooms()))];
  tell_room(this_object(),random(2)?"You're blinded by wind and sand!\n"
                                   :"You spin dizzily around the inside of the tornado.\n");
  tell_room(PATH+current_room,"A sandy whirliwind spins past you.\n");
  call_out("twist",4+random(5));
}
void release(object targ) {
  remove_call_out("twist");
  tell_room(PATH+current_room,targ->query_name()+" falls out of the air and lands HARD.\n");
  tell_object(targ,"You finally fly free of the whirliwind and...\n\n\n\n\n"+
  "\t\tDROP\n\n\n\t\t\tLIKE\n\n\n\t\t\t\tA\n\n\n\t\t\t\t\tSTONE!\n");
  move_object(targ,(object)master->query_room(PATH+current_room));
  targ->hit_player(random(45));
}
