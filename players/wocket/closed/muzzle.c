#include "/players/wocket/closed/ansi.h"

id(str){ return str == "muzzle"; }
drop(){ return 0; }

short(){ return "A muzzle (worn)"; }
init(){
  add_action("nodo","shout");
  add_action("nodo","gossip");
  add_action("nodo","risque");
  add_action("nodo","stt");
  add_action("nodo","ste");
  add_action("nodo","babble");
  add_action("nodo","equip");
}

nodo(str){
  write("Your muzzle prevents you from doing that.\n");
  return 1;
}
