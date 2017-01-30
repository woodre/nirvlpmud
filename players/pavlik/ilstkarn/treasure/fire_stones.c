#include <ansi.h>

int stones;

reset(arg){
  if(arg) return;
  stones = 5 + random(14);
}

id(str) {
  return str == "fire stones" || str == "stones" || str == "fire_stones";
}

long(){
  write(
  "The small lava stones are very hot to touch.  It seems that there is a\n"+
  "fire burning within them.\n"+
  "You have "+stones+" fire stones.\n");
  return;
}

short(){
  if(stones == 1) return "A "+RED+"Fire Stone"+NORM;
  return RED+"Fire Stones"+NORM+" ("+stones+")";
}

get() {
  if(present("fire_stones", this_player())) {
	present("fire_stones", this_player())->add_stones(stones);
	destruct(this_object());
	return;
  }
  return 1;
}

add_stones(i) { stones += i; }
query_stones() { return stones; }

query_weight() {
  return 1;
}

query_value() {
  return stones * 5;
}

query_save_flag() {
  return 1;
}

