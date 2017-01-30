/* soak heal, 3 charges @ +35 for 1200 coins  */

#define tpn this_player()->query_name()  /* player name  */
#include "/players/eurale/closed/ansi.h"
int number;

id(str) { return str == "tea" || str == "sassafras" || str == "flask"; }
short() { return "A flask of invigorating sassafras"; }
is_heal() { return "intox"; }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (number * 300); }
long() {
	write("A flask of invigorating sassafras tea.\n"+
	      "You may 'swig' another "+number+" swallows.\n"); }
reset(arg) {
  if(arg) return;
  number = 3;
}

init() {
  add_action("swig","swig"); }

swig(str) {
if(str == "sassafras" || str == "tea") {
  if(!call_other(this_player(),"drink_soft", 14)) return 0;
write("You take a swig of "+BOLD+"sassafras tea"+NORM+".\n");
say(tpn+" takes a swig of sassafras tea.\n");
  number = number - 1;
call_other(this_player(),"heal_self",35);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(BOLD+"You empty the flask of sassafras tea.\n"+NORM+
        "It certainly refreshed you....\n"+
        "You then smash the flask...\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
