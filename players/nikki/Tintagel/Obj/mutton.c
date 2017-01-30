#define tpn this_player()->query_name()  /* player name  */
#include "/players/nikki/ansi.h"
int number;

id(str) { return str == "mutton" || str == "leg"; }
short() { return "A leg of roasted mutton"; }
is_heal() { return "food"; }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (number * 300); }
long() {
	write(HIR+"A leg of roasted mutton.\n"+NORM+
	      "You may 'devour' another "+number+" bites of delicious mutton.\n"); }
reset(arg) {
  if(arg) return;
  number = 3;
}

init() {
  add_action("devour","devour"); }

devour(str) {
if(str == "mutton") {
  if(!call_other(this_player(),"eat_food", 14)) return 0;
write("You consume a chunk of mutton.\n");
say(tpn+" chomps on a chunk of mutton.\n");
  number = number - 1;
call_other(this_player(),"heal_self",50);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(BOLD+"You gnaw on the bone."+NORM+"\n"+
        "It was very filling....\n"+
        "You lick your lips wishing you had more...\n");
  say(tpn+" licks their fingers as they finish the mutton.\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
