#include "/players/hippo/rvd.h"

int total;

id(str) { return str == "chips"; }
short() {return"Abag of chips, laying on the table";}
long() {write("This is a bag of chips. You could eat them, of course.\n");}
get() { write("Please, leave it on the table.\n"); return 0; }
drop() {return 0;}
init() { add_action("eat","eat"); }
reset() { total=15; }
eat(str)
{ if(str=="chips")
  { write("Hmmm... that tastes good!\n");
    say("The bag knarps.. "+CTP+" eats some chips.\n");
    total=total-1;
    if(total==0)
    { write("That bag is empty. You throw it away.\n"+
            "If you want to have more chips, order it from the barkeeper\n");
      say("The bag of chips is empty. "+CTP+" throws it away.\n"+
            "If you want to have more chips, order it from the barkeeper\n");
      destruct(this_object());
    }
  }
  else write("Sorry?\n");
  return 1;
}
