
#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()  /* player name  */
int number;

id(str) { return str == "candy" || str == "rock candy"; }
short() { return
  BOLD+"A "+RED+"colorful "+GRN+"sack "+YEL+"of "+CYN+"rock "+
  "candy."+NORM; }
is_heal() { return "food"; }
query_save_flag() { return 1; }
query_value() { return (number * 300); }
long() {
	write("A colorful sack of rock candy.\n"+
	      "You may 'suck' another "+number+" rocks.\n"); }
reset(arg) {
  if(arg) return;
  number = 5;
}

init() {
  add_action("suck","suck"); }

suck(str) {
if(str == "rock" || str == "candy") {
  if(!call_other(this_player(),"eat_food", 6)) return 0;
write("You suck on a rock of candy.\n");
say(tpn+" sucks on some candy.\n");
  number = number - 1;
call_other(this_player(),"heal_self",50);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(BOLD+"You finish the rock candy.\n"+NORM+
	 "It was certainly sweet and good...\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
