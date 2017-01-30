#include "std.h"
int drinks, price;

id(str){
  return str == "thermos" || str == "coffee" || 
  str == "thermos of coffee";
}

reset(arg) {
 if(!arg)
  drinks = 3;
  price = 80 * drinks;
}

long() {
  write(
  "A thermos of hot steaming coffee.\n"+
  "There are "+drinks+" cups left.\n");
}

short() {
  return "A Coffee Thermos ("+drinks+")";
}

get(){ return 1; }

query_value(){ return price; }

query_weight(){ return 1; }

query_save_flag(){ return 1; }

init() {
  add_action("drink_coffee","drink");
}

drink_coffee(str){
  object obj;

  if(str == "coffee"){
    obj = this_player();

  write(
  "You unscrew the cap and pour yourself a hot cup of coffee.\n"+
  "Mmmmmm, that tastes good! (funny, he never asks for seconds\n"+
  "of MY coffee...)\n");
  say(capitalize(obj->query_name())+" pours himself a hot cup of "+
  "coffee.\n");
  obj->drink_alcohol(-5);
  drinks = drinks - 1;
  
  if(drinks == 0){
    write("You toss the empy thermos away (litterbug).\n");
    obj->add_weight(-1);
    destruct(this_object());
    return 1;
    }

  if(drinks == 1)
    write("There is 1 cup of coffee left.\n");
  else
    write("There are "+drinks+" cups of coffee left.\n");

  return 1;
  }
}
