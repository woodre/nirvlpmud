#include "std.h"
int amount;

id(str){
  return str == "burger" || str == "hamburger";
}

set_amount(str){ amount = str; }

reset(arg) {
}

long() {
  write(
  "A delicous patty of meat thats very healthy too!\n");
}

short() {
  return "A Nature Burger";
}

get(){ return 1; }

query_value(){ return 25; }

query_weight(){ return 1; }

init() {
  add_action("eat_burger","eat");
}

eat_burger(str){
  object obj;

  if(str == "burger" || str == "hamburger"){
    obj = this_player();

    if(!obj->eat_food(5)){
      return 1;
      }

    write(
    "You scarf down a nature burger.\n"+
    "Mmmm hmmm, does that taste good!  And healthy too!\n");
    say(capitalize(obj->query_name())+" eats a nature burger.\n");
    obj->add_hit_point(amount);
    destruct(this_object());
    return 1;
    }
}
