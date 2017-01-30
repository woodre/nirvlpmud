/* food heal, 1 charges @ +35 worth 300 coins  */
#define tpn this_player()->query_name()  /* player name  */
#include "/players/cosmo/closed/ansi.h"

id(str) { return str == "soup" || str == "cup"; }
short() { return "A cup of "+YEL+"Crab Bisque"+NORM+" soup"; }
is_heal() { return "food"; }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (300); }
long() {
  write(short()+"\n"+
        "A cup of crab bisque soup.\n"+
        "Eat it if you are hungry.\n"); }
reset(arg) {
  if(arg) return;
}

init() {
  add_action("chow","eat"); }

chow(str) {
if(str == "soup") {
  if(environment() != this_player()) return;
  if(!call_other(this_player(),"eat_food", 11)) return 0;
  write("You slurp down the delicious soup.\n");
  say(tpn+" slurps down the soup.\n");
  call_other(this_player(),"heal_self",35);
  call_other(this_player(),"recalc_carry");
  destruct(this_object());
  }
return 1; }

get() { return 1; }

query_weight() { return 1; }

