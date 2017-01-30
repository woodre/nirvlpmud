#include "../defs.h"

id(str) { return str == "sign"; }

init() { add_action("read","read"); }

read() {
     long();
      return 1;
}

short() { return "A Large sign"; }

long() {
  cat(DOCPATH+"sign");
  return;
}
