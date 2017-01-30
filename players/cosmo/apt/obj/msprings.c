/* soak heal, 1 charges @ +35 worth 300 coins  */
#define tpn this_player()->query_name()  /* player name  */
#include "/players/cosmo/closed/ansi.h"

id(str) { return str == "water" || str == "bottle" || str == "springs"; }
short() { return "A bottle of "+GRN+"Moland Springs"+NORM+" water"; }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (300); }
long() {
  write(short()+".\n"+
        "Crisp, clean, and fresh -- delicious water.\n"+
        "Take a drink or a swig to refresh yourself.\n"); }
reset(arg) {
  if(arg) return;
}

init() {
  add_action("h2o","drink"); 
  add_action("h2o","swig"); }

h2o(str) {
  if(str == "water" || str == "springs") {
    if(!call_other(this_player(),"drink_soft", 11)) return 0;
    write("You guzzle down the refreshing water.\n");
    say(tpn+" guzzles the bottle of water.\n");
    call_other(this_player(),"heal_self",35);
    call_other(this_player(),"recalc_carry");
    destruct(this_object());
    return 1;
  }
}

get() { return 1; }

query_weight() { return 1; }

