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

test(string str) {
  int i, j;
  j = atoi(str);
  for( i=0; i<17; i++ ) {
    if( j & i )
      write(i + " includes " + j + "\n");
  }
  return 1;
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

