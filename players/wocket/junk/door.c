#include "/players/wocket/closed/ansi.h"

id(str){ return str == "door"; }
short(){ return HIY+"A giant oak door ["+NORM+"east"+HIY+"]"+NORM; }
long(){ write("This is a giant oak door that opens to the east.\n"); }


init(){
  add_action("unlock","unlock");
  add_action("open","open");
  add_action("east","east");
}

east(){
  if(doorclosed == 1){
  write("The door is closed.\n");
  return 1;
}
  return 0;
}
