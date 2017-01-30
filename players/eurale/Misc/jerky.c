/* food heal, 3 charges @ +35 for 1200 coins  */

#define tpn this_player()->query_name()  /* player name  */
#include "/players/eurale/closed/ansi.h"
int number;

id(str) { return str == "jerky" || str == "strip"; }
short() { return "A strip of dried beef jerky"; }
is_heal() { return "food"; }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (number * 300); }
long() {
	write("A strip of dried beef jerky.\n"+
	      "You may 'chew' another "+number+" bites.\n"); }
reset(arg) {
  if(arg) return;
  number = 3;
}

init() {
  add_action("chew","chew"); }

chew(str) {
if(str == "jerky") {
  if(!call_other(this_player(),"eat_food", 14)) return 0;
write("You take a bite of jerky.\n");
say(tpn+" takes a bite of jerky.\n");
  number = number - 1;
call_other(this_player(),"heal_self",35);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(BOLD+"You finish the strip of jerky."+NORM+"\n"+
        "It was certainly good....\n"+
        "You wish there was more...\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() { return 1; }
