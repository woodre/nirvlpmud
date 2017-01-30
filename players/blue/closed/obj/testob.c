#include "/players/blue/closed/lib/color.h"
#include "/players/blue/closed/lib/basic.h"

id(str) { return str == "test"||str == "testob"; }
short() { return "A test object"; }
long() { if(LEVEL < 20) {
   write("This is not for you to have.\n");
   destruct(TO);
   return 1;
   } else write("A test object.\n");
}
query_weight() { return 0; }
get() { return 1; }
drop() { return 1; }
query_value() { destruct(TO); }

init() {
  
   add_action("test_function","test");
   add_action("get_directory","gdir");
   add_action("test_two","testtwo");

}

test_function() {
   int n;
   n = 1;
   while(n < 50) {
      write(ESC+"[40m"+WHI+NOSTYLE);
      write(n);
      write(" "+ESC+"["+n+"m"+" check \n");
      n+= 1;
   }
   write("Done.\n");
   return 1;
}

test_two(str) {
   write(ESC+"["+str+"mCheck.\n");
   return 1;
}

get_directory(str) {
   int n;
   string *dir;
   n = 0;
   dir = get_dir(str);
   while(n < sizeof(dir)) {
      write(n +": "+dir[n]+".\n");
   n+=1;
   }
   return 1;
}
