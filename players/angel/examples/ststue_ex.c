#include <ansi.h>

id(str) {
  return str=="plaque" || str== "statue";
}


long()
 {
 write("This is a beatuiful statue of the ancient Unicorn General.\n\
blah blah blah........\n\n");
}

short() {
  return ""+HIC+"Unicorn statue"+NORM+"";
}

init() {
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(str != "plaque") return 0;
  long();
  return 1;
}