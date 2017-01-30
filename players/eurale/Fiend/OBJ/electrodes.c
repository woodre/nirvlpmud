/* Values changed due to upgrade in level of the monster
completed by Pestilence per Dragnar 8-9-2014 */
#define tpn this_player()->query_name()  /* player name  */
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
int number;

id(str) { return str == "electrodes"; }
short() { return "Two shiney metal neck electrodes"; }
query_save_flag() { return 1; }
query_value() { return (number * 700); }
long() { write(
  "These two shiney electrodes were attached to Frankenstein's neck\n"+
  "to animate him.  They hold heart-starting charges for those who\n"+
  "'fibulate' or they may be 'bartered' for cash.\n"+
  "You currently have "+number+" charges left.\n");
  }
reset(arg) {
  if(arg) return;
  number = 3;
}

init() {
  add_action("fibulate","fibulate");
  add_action("Barter","barter");
}

fibulate() {
  if(!call_other(this_player(),"eat_food", 6)) return 0;
  write("You grab hold of the two charged electrodes and.....\n"+
	"BZZZZZZZZZZ...... you feel your heart race...\n");
  number = number - 1;
call_other(this_player(),"heal_self",50);
call_other(this_player(),"recalc_carry");
if(!number) {
  write(BOLD+"You grab the electrodes and completely discharge them..."+NORM+"\n");
  destruct(this_object()); }
 return 1; }

Barter(str) {
int num;
if(!present("sedjak",ETP)) return 0;
if(str == "electrodes") {
  num = number * (2500 + random(300));
  write("Sedjak rubs his hands together in anticipation.  He takes the\n"+
        "shiney electrodes and quickly stuffs them in his pocket.  With\n"+
        "a grin, he drops "+num+" coins in your money pouch.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}


get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
