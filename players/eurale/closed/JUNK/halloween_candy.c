/* food heal, 3 charges @ +35 for 1200 coins  */

#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()  /* player name  */
int chance;


id(str) { if(str == "candy" || str == "rock") return 1;
  }
short() { return
  BOLD+"A "+RED+"colorful "+GRN+"piece "+YEL+"of "+CYN+"rock "+
  "candy."+NORM+"\n"+
  BOLD+"   EURALE'S TRICK OR TREAT"+NORM; }
is_heal() { return "food"; }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return 100; }
long() { write(
	"This is a colorful piece of Trick-or-Treat rock candy.  All\n"+
	"you have to do is [suck candy].  If you're lucky, you'll get\n"+
	"a 35 hps/sps heal but if you're not..... the 'Trick' is on\n"+
	"you and you'll need some help......  Good Luck!\n");
	}
reset(arg) {
  if(arg) return;
}

init() {
  add_action("suck","suck"); }

suck(str) {
if(str == "rock" || str == "candy") {
chance = random(14);
if(chance > 3) {
  if(!call_other(this_player(),"eat_food", 5)) return 0;
write("You suck on a rock of candy.\n");
say(tpn+" sucks on some candy.\n");
call_other(this_player(),"heal_self",35);
call_other(this_player(),"recalc_carry");
  write("You finish the rock candy.\n"+
	 "It was certainly sweet and good...\n");
  destruct(this_object());
 return 1; }
else {
  write("Oh Oh, You're in real trouble...\n");
  this_player()->frog_curse(1);
  destruct(this_object());
  return 1; }
 return 1; }
}

get() { return 1; }
