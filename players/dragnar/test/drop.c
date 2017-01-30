#include <ansi.h>

id(string str) {

   return str == "test" || str == "test_obj";
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

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 10; }

