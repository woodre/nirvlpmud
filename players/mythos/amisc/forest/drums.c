#include "/players/mythos/closed/ansi.h"

inherit "obj/treasure";

int x;

reset(arg) {
  if(arg) return;
  set_id("drums");
  set_short("A small set of hand drums");
  set_long("The drums of Thunder that Raiden holds.\n"+
           "You could 'sound' the drums.\n");
  set_weight(3);
  set_value(10000);
}

init() {
  ::init();
  add_action("sound","sound");

}

sound() {
  x=15;
  write("You begin to pound your hands on the drum.\n");
  tell_room(environment(this_player()),"\nThunder resounds through the room!\n");
  call_out("thunder",3);
  return 1;}

thunder() {
int y, z;
y=random(5);
z=random(10);
  if((x>0) && environment(environment())) {
  switch(y) {
  case 0: tell_room(environment(environment(this_object())),
          "\nThunder resounds through the room!\n"); break;
  case 1: tell_room(environment(environment(this_object())),BOLD+
          "\n\tBOOM!\n\n\t\tBOOM!\n\n\t\t\tBOOM!\n\n"+NORM);   break;   
  case 2: tell_room(environment(environment(this_object())),RED+
          "\nThe ground shakes!\n"+NORM);   break;   
  case 3: tell_room(environment(environment(this_object())),
          "\nThunder resounds through the room!\n"); break;
  case 4: tell_room(environment(environment(this_object())),
          "\nRUMBLE\n"); break;
  }
  x=x-1;
  call_out("thunder",5);
  return 1;}
  tell_object(environment(this_object()),"You stop sounding the drums.\n");
return 1;}


query_save_flag()  { return 0; } 
