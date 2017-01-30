#include <ansi.h>

id(str) { return str == "sign"; }

init() { add_action("read","read"); }

read() {
     long();
      return 1;
}

short() { return "A Large "+HIR+"sign"+NORM+""; }

long() {
     cat("/players/angel/masons/SIGN");
     return 1;
}
