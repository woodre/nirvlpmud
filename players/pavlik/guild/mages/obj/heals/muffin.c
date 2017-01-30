#include "std.h"
int drinks, price;

id(str){
  return str == "muffin" || str == "blueberry muffin";
}

reset(arg) {
}

long() {
  write(
  "A delicous little blueberry muffin, straight from\n"+
  "Biago's oven.\n");
}

short() {
  return "A Blueberry Muffin";
}

get(){ return 1; }

query_value(){ return 150; }

query_weight(){ return 1; }

init() {
  add_action("eat_muffin","eat");
}

eat_muffin(str){
  object obj;

  if(str == "muffin"){
    obj = this_player();

    if(!obj->eat_food(9)){
      return 1;
      }

    write(
    "You inhale a blueberry muffin.\n");
    say(capitalize(obj->query_name())+" inhales a blueberry muffin.\n");
    obj->heal_self(10);
    destruct(this_object());
    return 1;
    }
}
