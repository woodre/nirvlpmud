#define tpn this_player()->query_name()  /* player name  */
#include "/players/eurale/closed/ansi.h"

id(str) { return str == "hickory nut" || str == "nut"; }
short() { return "A large hickory nut"; }
query_save_flag() { return 1; }
query_value() { return 5; }
long() { write(
  "This large hickory nut will provide a tasty snack to the hungry\n"+
  "traveler if they chew it.\n");
  }
reset(arg) {
  if(arg) return;
}

init() {
  add_action("chew","chew");
}

chew(str) {
if(!str) { write("Chew what?\n"); return 1; }
if(str == "hickory nut" || str == "nut") {
  write("You break the shell off of the tasty nut and pop it into\n"+
 	"your mouth.  You chew it and savor the nutty flavor that\n"+
	"it provides as well as the extra energy.\n");
  say(tpn+" shucks and eats a hickory nut.\n");
call_other(this_player(),"eat_food",6);
call_other(this_player(),"heal_self",20);
destruct(this_object());
 return 1; }
}

get() { return 1; }

query_weight() {
  return 0; }
