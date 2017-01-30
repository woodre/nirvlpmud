/* food heal, 4 charges @ +35 for 1500 coins  */
#define tpn this_player()->query_name()  /* player name  */
#include "/players/cosmo/closed/ansi.h"

int number;

id(str) { return str == "soup" || str == "bowl"; }
short() { return "A bowl of "+YEL+"Crab Bisque"+NORM+" soup"; }
is_heal() { return "food"; }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (number * 300); }
long() {
  write(short()+".\n"+
        "Eat it if you are hungry.\n"); }
reset(arg) {
  if(arg) return;
  number = 4;
}

init() {
  add_action("chow","eat"); }

chow(str) {
if(str == "soup") {
  if(environment() != this_player()) return;
  if(!call_other(this_player(),"eat_food", 11)) return 0;
  write("You slurp down a spoonful of soup.\n");
  say(tpn+" slurps down some soup.\n");
  number = number - 1;
  call_other(this_player(),"heal_self",35);
  call_other(this_player(),"recalc_carry");
  if(!number) {
    write(BOLD+"You lick the edges of the bowl as you finish off the soup.\n"+NORM);
    destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }

