#include <ansi.h>

id(string str) {

   return str == "test" || str == "tester";
}


init() {
   add_action("test","test");
}
reset(arg){
  if(arg) return;
}

short() { 
  return "Tester";
}

long() {
write("test\n");
}


test(string str) {
  write_file("/players/dragnar/tst", HIR+str+NORM+"\n");
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

