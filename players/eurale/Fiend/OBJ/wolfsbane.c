#define tpn this_player()->query_name()  /* player name  */
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
int number;

id(str) { return str == "wolfsbane" || str == "bouquet"; }
short() { return "A bouquet of wolfsbane"; }
query_save_flag() { return 1; }
query_value() { return (number * 700); }
long() { write(
  "This is a small bouquet of the wild-growing wolfsbane.  Its heady\n"+
  "aroma when smelled is enough to pick up anyone's spirits or it\n"+
  "can be 'barter'ed for a small amount of gold.\n");
  }
reset(arg) {
  if(arg) return;
  number = 7;
}

init() {
  add_action("Inhale","smell");
  add_action("Barter","barter");
}

Inhale(str) {
if(!str) { write("Smell what?\n"); return 1; }
if(str == "wolfsbane" || str == "bouquet") {
  write("You lower your nose into the fragrant bouquet and inhale\n"+
	"deeply.  The wonderful aroma of the wolfsbane makes you feel\n"+
	"refreshed and perky.\n");
  number = number - 1;
call_other(this_player(),"add_spell_point",40);
call_other(this_player(),"recalc_carry");
if(!number) { write(
  BOLD+"With a final sniff, the bouquet wilts and falls apart."+
  NORM+"\n");
  destruct(this_object()); }
 return 1; }
}

Barter(str) {
int num;
if(!present("rue",ETP)) return 0;
if(str == "wolfsbane" || str == "bouquet") {
  num = number * (700 + random(30));
  write("Rue takes the bouquet of wolfsbane and smells it deeply.\n"+
        "She sighs as she hands you "+num+" coins and says, 'These\n"+
        "are my favorite flower.'\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}


get() { return 1; }

query_weight() { return 1; }
