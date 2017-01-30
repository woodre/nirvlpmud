/* Controls for hide-in-shadows */
#include "../DEFS.h"
status id(string str) { return str == "_drivers_seat_"; }

void init() { 
  add_action("out","out");
  add_action("say","say");
  add_action("loook","look");
  add_action("loook","l");
}

status get()   { return 0; }
status drop()  { return 1; }
string short() { return "shadows"; }
void long()    { write("The shadows are dark.\n"); }

status out() {
  object shadowsVehicle;
  if (present("_hide_in_shadows_vehicle_", environment(environment(TP)))) {
    shadowsVehicle = present("_hide_in_shadows_vehicle_", environment(environment(TP)));
  }
  move_object(this_player(),
    environment(environment(TP)));
  write("You leave the shadows.\n");
  if(!TP->query_invis()) {
    say(TPN+" emerges from the shadows.\n");
  }
  if (shadowsVehicle) destruct(shadowsVehicle);
  destruct(this_object());
  return 1; 
}

status say(string str) {
  if(!str) {
    write("Say what?\n");
    return 1; }
  tell_room(environment(environment(TP)),
    "A voice from the shadows says: "+str+"\n");
  write("You say: "+str+".\n");
  return 1; 
}

status loook(string str) {
  object ob, eob;
  ob = environment(TP);
  eob = environment(ob);
  move_object(this_player(), eob);
  if(!str) {
    call_other(TP, "glance");
    move_object(TP, ob);
    return 1; }
  if(str == "at shadows") {
    move_object(TP, ob);
    write(
"     You are hiding in the shadows.\n"+
"To return from the shadows, type 'out'.\n"+
"You may look and say as normal.\n"+
"Your current location is: "+environment(environment(
 this_player()))->short()+"\n");
    return 1; 
  }
  call_other(TP, "look "+str);
  move_object(TP, ob);
  return 1;
}

