/* food heal, 3 charges @ +35 for 1200 coins  */

#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()  /* player name  */
int full, number, number2;

id(str) { if(str == "candy" && full) return 1;
	return str == "sack"; }
short() { if(full) return
  BOLD+"A "+RED+"colorful "+GRN+"sack "+YEL+"of "+CYN+"rock "+
  "candy."+NORM; }
is_heal() { return "food"; }
query_potence() { return 25; }
query_save_flag() { return 1; }
query_value() { if(full) return 6; else return (number*300); }
long() {
	write("A colorful sack of rock candy.\n"+
	      "You may 'suck' another "+number+" rocks.\n"); }
reset(arg) {
  if(arg) return;
  number2 = 0;
  number = 6;
  full = 1;
}

init() {
  add_action("suck","suck"); }

suck(str) {
if(str == "rock" || str == "candy") {
  if(!call_other(this_player(),"eat_food", 10)) return 0;
write("You suck on a rock of candy.\n");
say(tpn+" sucks on some candy.\n");
  number2 = number2 + 1;
  number = number - 1;
call_other(this_player(),"heal_self",25);
call_other(this_player(),"recalc_carry");
if(!number) {
  full = 0;
  write("You finish the rock candy.\n"+
	 "It was certainly sweet and good...\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
