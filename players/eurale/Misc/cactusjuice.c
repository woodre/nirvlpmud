
#define tpn this_player()->query_name()  /* player name  */
#include "/players/eurale/closed/ansi.h"
int number;

id(str) { return str == "jug" || str == "juice"; }
short() { return "A small jug of cactus juice"; }
query_save_flag() { return 1; }
query_value() { return (number * 300); }
long() {
  write("This is a small, brown-glass, jug filled with freshly\n"+
	"squeezed juice from the prickly pear cactus.  There is\n"+
	"a small circular finger hold to tip the jug so you can\n"+
	"drink.  Cactus juice is rumored to have a very sobering\n"+
	"effect on anyone who is intoxicated...\n"+
	"You may 'tip' another "+number+" swallows.\n"); }

reset(arg) {
  if(arg) return;
  number = 3;
}

init() {
  add_action("tip_jug","tip"); }

tip_jug(str) {
if(str == "juice" || str == "cactus juice") {
  if(!call_other(this_player(),"drink_alcohol", -13)) return 0;
write("You tip the jug up to your lips and take a\n"+
      "swallow of the vile tasting cactus juice...\n");
say(tpn+" takes a swallow of cactus juice.\n");
  number = number - 1;
call_other(this_player(),"recalc_carry");
if(!number) {
  write(BOLD+"You drain the jug of cactus juice.\n"+NORM+
		"You shake your head from the vile taste...\n"+
		"and then you throw the jug against a large rock...\n"+
		"smashing it to pieces....\n");
  destruct(this_object());
  }
 return 1; }
}

get() { return 1; }

querty_weight() { return number; }
