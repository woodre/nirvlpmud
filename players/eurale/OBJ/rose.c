#include "/players/eurale/defs.h"
inherit "obj/clean";

id(str)  {
  return str == "rose" || str == "blue rose";
}

short() {
  return "small red rose "+HIR+"@"+NORM+HIG+")->--"+NORM; }

long() { write(
  "A small, fragrant blue rose in full bloom.  It fills the air\n"+
  "with a heady, fresh aroma.\n");
}

get()  { return 1;  }

query_weight()  {  return 1;  }

query_value()  {  return 1;  }

init()  {
 add_action("smell_rose", "smell");
}

smell_rose(str)  {
if((!str) || !id(str)) { return 0; }

write("You lift the delicate blue rose to your nose and inhale the\n"+
       "heady aroma of it's essence.\n");
say(capitalize(TPRN)+" smells the fragrant blue rose.\n");
return 1;
}
