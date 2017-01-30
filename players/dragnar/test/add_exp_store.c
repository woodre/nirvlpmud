#include <ansi.h>

int i;

id(string str) {

   return str == "test" || str == "tester";
}


init() {
  add_action("test", "test");
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


test(string args) {
  call_other("obj/exp_store.c","collector","Cooper",e);
  call_other("obj/exp_store.c","collector","Grimer",e);
  return 1;

}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

