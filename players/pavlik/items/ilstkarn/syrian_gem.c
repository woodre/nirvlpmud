#include <ansi.h>

reset(arg){
  if(arg) return;
}

id(str) {
  return str == "gem" || str == "stone" || str == "gemstone" ||
  str == "syrian gem" || str == "syrian gemstone" || str == "syrian_gem";
}

long(){
  write(
  "The Syrian Gemstone is a beautiful ice-blue gem.  It is finely\n"+
  "cut and the stone sparkles brilliantly in the sunlight.  Syrian\n"+
  "stones are also known to have magical properties, specifically\n"+
  "they provide resistance to evil Fire-Magic when worn on the body.\n");
  return;
}

short(){
  return "A "+HIB+"Syrian"+NORM+" Gemstone";
}

get() {
  return 1;
}

query_weight() {
  return 1;
}

query_value() {
  return 850;
}

query_save_flag() {
  return 1;
}

init() {
  add_action("nowear","wear");
}

nowear(str) {
  if(id(str)) {
    write("You cannot wear the stone all by itself.\n");
    write("Perhaps you can find something to Mount it on...\n");
    return 1;
  }
}

