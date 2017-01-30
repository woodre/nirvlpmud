#include "/players/hippo/rvd.h"
int total;

id(str) { return str == "popcorn"; }
short() {return"A bowl of popcorn, laying on the table";}
long() {write("You can eat it, of course.\n");}
get() { write("Please, leave it on the table.\n"); return 0; }
drop() {return 0;}
init() { add_action("eat","eat"); }
reset() { total=10; }
eat(str)
{ if(str=="popcorn")
  { write("Hmmm... you like that taste!\n");
    say("You hear "+CTP+", while he eats some popcorn.\n");
    total=total-1;
    if(total==0)
    { write("You finished the popcorn. If you want some more, order it\n"+
            "from the barkeeper.\n");
      say(CTP+" finished the popcorn. You can ask the barkeeper for a new plate.\n");
      destruct(this_object());
    }
  }
  else write("Sorry?\n");
  return 1;
}
