#include "defs.h"

inherit "/obj/treasure.c";

reset(arg) {
  if(arg) return;
  set_id("escape");
}

void init() {
  add_action("escape","escape");
}

int sqr(int x) {
  int i;
  int answer;
  if(x == 0)
    return 1;
  else
    answer = 2;
  for(i=1; i < x; i++)
    answer*=2;
  return answer;
}

escape() {
  string esc;
  int i;
  esc = ESC;
  for(i=0; i < 8; i++) {
    write(sqr(i));
    if(esc[0] & sqr(i))
      write("1");
    else
      write("0");
    write("\n");
  }
  write("\n");
  return 1;
}
