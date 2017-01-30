#include <ansi.h>

id(string str) {

   return str == "test" || str == "test_obj";
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

test() {
  int i, size;
  object *inv;
  string *extra_look;
  string extra;
  
  inv = all_inventory( this_player() );
  
  return 1;
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

