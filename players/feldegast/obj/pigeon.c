#include "defs.h"

inherit "/obj/treasure.c";

string message;
object target;

void reset(int arg) {
  if(arg) return;
  set_id("pigeon");
  set_short("A homing pigeon");
  set_weight(1);
  set_value(500);
}

void long(string str) {
  write("This is a dark grey homing pigeon with bright blue string\n"+
        "tied to its feet for tying messages.  You can 'write' a new\n"+
        "message for it, and then have it 'seek' someone out.\n");
  if(message)
    write("It has a message capsule tied to its leg.  You can 'read'\n"+
          "the message.\n");
}

void init() {
  add_action("cmd_read","read");
  add_action("cmd_write","write");
  add_action("cmd_seek","seek");
}

int cmd_write(string str) {
  write("End the message with **\n[");
  message="";
  input_to("writing");
  return 1;
}

void writing(string str) {
  if(str!="**") {
    message+=str+"\n";
    write("[");
    input_to("writing");
  }
  else
    write("Okay.\n");
}

int cmd_read(string str) {
  if(!str || str!="message") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The message says:\n");
  write("------------------------------------------------------------\n");
  write(message);
  write("------------------------------------------------------------\n");
  return 1;
}

int cmd_seek(string str) {
  if(!str) {
    notify_fail("Seek whom?\n");
    return 0;
  }
  target=find_player(str);
  if(!target) {
    notify_fail("That player is not on.\n");
    return 0;
  }
  write("You toss the pigeon into the air and watch it fly off.\n");
  say(TPN+" tosses a pigeon into the air and watches it fly off.\n");
  move_object(this_object(),"/room/void.c");
  this_player()->add_weight(-local_weight);
  call_out("flight",3,1);
  return 1;
}

void flight(int arg) {
  if(!target) return;
  switch(arg) {
    case 1: tell_object(target,"You notice a pigeon flying overhead.\n");
            call_out("flight",3,2);
            break;
    case 2: tell_object(target,"The pigeon circles down towards you.\n");
            call_out("flight",3,3);
            break;
    case 3: tell_object(target,"The pigeon softly lands in your hands.\n");
            move_object(this_object(),target);
            target->add_weight(1);
            break;
  }
}
