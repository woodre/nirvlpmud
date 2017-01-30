#define tpn this_player()->query_name()
#include "/players/nikki/ansi.h"
int number;

id(str) { return str == "milk" || str == "skin"; }
short() { return "A skin of fresh goat's milk"; }
is_heal() { return "intox"; }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (number * 300); }
long() {
	write(HIG+"A skin of fresh goat's milk.\n"+
	      "You may 'guzzle' another "+number+" times.\n"+NORM); }
reset(arg) {
  if(arg) return;
  number = 3;
}

init() {
  add_action("guzzle","guzzle"); }

guzzle(str) {
if(str == "milk") {
  if(!call_other(this_player(),"drink_soft", 14)) return 0;
write("You guzzle down the refreshing "+BOLD+"goat's milk"+NORM+".\n");
say(tpn+" guzzles down the fresh goat's milk.\n");
  number = number - 1;
call_other(this_player(),"heal_self",50);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(HIG+"You drink the last drop of milk.\n"+NORM+
        "It makes you thirsty for more...\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
