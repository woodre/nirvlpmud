/* intox heal, 3 charges @ +35 for 1200 coins  */

#define tpn this_player()->query_name()  /* player name  */
#include "/players/eurale/closed/ansi.h"
int number;

id(str) { return str == "rotgut" || str == "bottle"; }
short() { return "A bottle of homemade rotgut"; }
is_heal() { return "intox"; }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (number * 300); }
long() {
	write("A bottle of homemade rotgut.\n"+
	      "You may 'drink' another "+number+" swallows.\n"); }
reset(arg) {
  if(arg) return;
  number = 3;
}

init() {
  add_action("drink","drink"); }

drink(str) {
if(str == "rotgut") {
  if(!call_other(this_player(),"drink_alcohol", 15)) return 0;
write("You take a drink of rotgut.\n");
say(tpn+" takes a drink of rotgut.\n");
  number = number - 1;
call_other(this_player(),"heal_self",35);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(BOLD+"You empty the bottle of rotgut.\n"+NORM+
        "It was certainly nauseating....\n"+
        "You then bust the bottle to pieces...\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
