#include <ansi.h>

id(str) {
  return str=="new sign" || str== "sign";
}


long()
 {
  write("You are about to enter a very dangerous area!\n\
If you are not in a party or very large you might think\n\
about turning around!!!! S E R I O U S L Y!!!!\n\n");
}

short() {
  return ""+HIR+"W A R N I N G"+NORM+" sign";
}

init() {
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(str != "sign") return 0;
  long();
  return 1;
}