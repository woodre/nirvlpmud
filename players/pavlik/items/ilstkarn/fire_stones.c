#include <ansi.h>
int stones;

reset(arg){
  if(arg) return;
  stones = 10+random(10);
}

id(str) {
  return str == "pouch" || str == "stones" || str == "fire_stones";
}

long(){
  write(
  "A tiny pouch with some stones in it.  The smallish stones gleam\n"+
  "with marvelous light, you wonder if they are magical...\n");
  if(stones == 1)
    write("There is 1 stone in the pouch.\n");
  else
    write("There are "+stones+" stones in the pouch.\n");
  return;
}

short(){
  return "A pouch of stones ["+stones+"]";
}

get() {
  if(present("fire_stones", this_player())) {
    write("You add the stones to your existing pouch.\n");
    present("fire_stones", this_player())->add_stones(stones);
    destruct(this_object());
    return;
  }
  return 1;
}

query_weight() {
  return 2;
}

query_value() {
  return 10 * stones;
}

query_save_flag() {
  return 1;
}

query_stones() { return stones; }

add_stones(i) {
  if(!environment())
    return;

  stones += i;
  if(stones < 0) stones = 0;

  if(stones == 0) {
    tell_object(environment(), "The pouch of stones is "+HIW+"empty"+NORM+".\n");
    environment()->add_weight(-2);
    destruct(this_object());
    return 1;
  }

  if(stones == 1)
    tell_object(environment(), "There is only "+HIW+"1 stone"+NORM+" left in the bag.\n");

  if(stones == 5)
    tell_object(environment(), "There are "+HIW+"5 stones"+NORM+" left in the bag.\n");

  if(stones == 10)
    tell_object(environment(), "There are "+HIW+"10 stones"+NORM+" left in the bag.\n");

  return 1;
}

