#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define tpn tp->query_real_name()
#define TP capitalize(tpn)

int amount;

id(str) { return str == "eye"; }

short() { return "The Eye of a Lesser SandWalker"; }

long() { write("A white gleaming eye stares back at you.\n"+
               "You may 'slurp' the eye "+amount+" times.\n");
        }
        
drop() { return 0; }
get() { return 1; }
query_save_flag() { return 1; }

query_weight() {
  if(amount > 0) return amount*2;
  return 1;
}

query_value() { return amount*700; }

reset(arg) { if(arg) return; amount = 5; }

init() {
  add_action("slurp","slurp");
}

slurp(str) {
  if(!str) return 0;
  if(str == "eye") {
    if(!tp->eat_food(6) || !tp->drink_soft(6)) return 0;
    tp->heal_self(35);
    write("You intake some of the eye's substance...\n"+
          "Thick gooey liquid courses down your throat.\n"+
          "You are slightly put off by the taste but you do feel better.\n");
    say(TP+" slurps at a white gooey looking eye.\n");
    amount = amount - 1;
    if(amount < 1) {
      write("You have partaken the last of this eye's substance.\n");
      tp->add_weight(query_weight());
      destruct(this_object());
    }
  return 1; }
}
