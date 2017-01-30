/* intox heal, 3 charges @ +35 for 1200 coins  */

#define tpn this_player()->query_name()  /* player name  */
#include "/players/nikki/ansi.h"
int number;

id(str) { return str == "mead" || str == "jug"; }
short() { return "A jug of homebrewed mead"; }
is_heal() { return "intox"; }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (number * 300); }
long() {
	write(HIR+"A jug of home brewed mead.\n"+NORM+
	      "You may 'swig' another "+number+" gulps.\n"); }
reset(arg) {
  if(arg) return;
  number = 3;
}

init() {
  add_action("swig","swig"); }

swig(str) {
if(str == "mead") {
  if(!call_other(this_player(),"drink_alcohol", 15)) return 0;
write("You take a swig of "+HIG+"mead"+NORM+".\n");
say(tpn+" takes a swig of mead.\n");
  number = number - 1;
call_other(this_player(),"heal_self",50);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(HIG+"You empty the jug of mead.\n"+NORM+
	  "You slurp the last drop from the jug's opening.\n"+
        "You then crush the jug to fragments...\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
