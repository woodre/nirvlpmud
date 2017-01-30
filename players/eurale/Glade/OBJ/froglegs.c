
#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()  /* player name  */
int number;

id(str) { return str == "legs" || str == "frog legs"; }
short() { return "Frog legs"; }
is_heal() { return "food"; }
query_save_flag() { return 1; }
query_value() { return (number * 405); }
long() { write(
  "A pair of small frog legs that could be eaten.\n"); }
reset(arg) {
  if(arg) return;
  number = 2;
}

init() {
  add_action("eat","eat"); }

eat(str) {
if(str == "legs" || str == "frog legs") {
  if(!call_other(this_player(),"eat_food", 9)) return 0;
write("You eat one of the tasty frog legs.\n");
say(tpn+" eats a tasty frog leg.\n");
  number = number - 1;
call_other(this_player(),"heal_self",27);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(BOLD+"You finish the frog legs and lick your fingers."+NORM+"\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
