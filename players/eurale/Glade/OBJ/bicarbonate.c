/* destuff heal, 5 charges @ -10 for 1800 coins  */

#define tpn this_player()->query_name()  /* player name  */
#include "/players/eurale/closed/ansi.h"
int number;

id(str) { return str == "bicarbonate"
		|| str == "tablets"; }

short() { return "bicarbonate of soda tablets"; }
long() { write(
  number+" small,white tablets of bicarbonate of soda for indigestion.\n"+
  "To illeviate that full feeling, you just 'munch' one.\n");
  }

query_save_flag() { return 1; }
query_value() { return (number * 90); }

reset(arg) {
  if(arg) return;
  number = 5;
}

init() {
  add_action("munch","munch"); }

munch(str) {
if(str == "bicarbonate" || str == "tablet") {
    write("You chew up the chalky tablet and feel better.\n");
    say(tpn+" chews on a chalky, white tablet.\n");
  number = number - 1;
call_other(this_player(),"add_stuffed",-10);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(BOLD+"You chew up your last bicarbonate tablet."+NORM+"\n\n");
  destruct(this_object());
  }
  return 1; }
}

get() { return 1; }

query_weight() { return number; }
