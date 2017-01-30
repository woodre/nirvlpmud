#include "std.h"
#include "/players/hippo/bs.h"
int drinks, price;

id(str) { return str == "dna"; }
reset(arg) {
}
long() {
   write("This is a dna-string. Normally it's full of heal-powers, but"+BS+
      "this string is broken. Some frame-shift mutants have messed it up."+BS);
}
short() {
   return "A DNA-string.";
}
get() {
    return 1;
}

query_weight() {
   return 1;
}
query_save_flag() { return 1; }
