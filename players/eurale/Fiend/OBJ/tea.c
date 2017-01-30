#define tpn this_player()->query_name()  /* player name  */
#include "/players/eurale/closed/ansi.h"
int number;

id(str) { return str == "tea" || str == "ginsing"; }
short() { return "A bottle of "+HIG+"ginsing tea"+NORM; }
query_save_flag() { return 1; }
query_value() { return (number * 500); }
long() { write(
  "A bottle of soothing ginsing tea.  It is rumored to have\n"+
  "amazing medicinal properties.  Drinks left: "+number+"\n");
}

reset(arg) {
  if(arg) return;
  number = 3;
}

init() {
  add_action("drink","drink"); }

drink(str) {
if(str == "ginsing" || str == "tea") {
  if(environment() != this_player()) return;
  if(!call_other(this_player(),"drink_soft", 10)) return 0;
write("You take a swig of soothing "+HIR+"ginsing tea"+NORM+"\n");
say(tpn+" takes a swig of ginsing tea.\n");
  number = number - 1;
call_other(this_player(),"heal_self",50);
call_other(this_player(),"recalc_carry");
if(!number) { write(HIG+
  "You drain the last drop of the greenish tea and feel wonderful.\n"+
  "As the air hits the empty bottle, it sizzles and disappears"+
  NORM+"\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
