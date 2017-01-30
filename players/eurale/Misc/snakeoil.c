/* desoak heal, 5 charges @ -10 for 1800 coins  */

#define tpn this_player()->query_name()  /* player name  */
#include "/players/eurale/closed/ansi.h"
int number;

id(str) { return str == "snakeoil" || str == "oil" || str == "bottle"; }
short() { return "A small bottle of potent snakeoil"; }
query_save_flag() { return 1; }
query_value() { return (number * 90); }
long() {
	write("A small bottle of potent snakeoil.\n"+
	      "You may 'gulp' another "+number+" swallows.\n"); }
reset(arg) {
  if(arg) return;
  number = 5;
}

init() {
  add_action("gulp","gulp"); }

gulp(str) {
if(str == "snakeoil") {
  if(!this_player()->query_soaked()) {
	write("You are no longer soaked.\n"); return 1; }
write("You take a gulp of snakeoil.\n");
say(tpn+" takes a gulp of snakeoil.\n");
  number = number - 1;
call_other(this_player(),"add_soaked",-10);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(BOLD+"You empty the bottle of snakeoil.\n"+NORM+
        "You feel relieved....\n"+
        "You break the tiny bottle to pieces...\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() { return 1; }
