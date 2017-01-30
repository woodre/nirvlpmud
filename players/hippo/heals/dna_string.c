#include "/open/ansi.h"
inherit "obj/treasure";
int drinks, price;

reset(arg) {
  if(arg) return;

set_id("dna");
set_alias("broken dna");
set_short(GRN+"broken dna"+NORM);
set_long(
  "This is a dna-string.  Normally it is full of healing powers but this string\n"+
  "is broken.  It has been altered by some frame shift mutants and must be\n"+
  "repaired to be useable.\n");
set_weight(1);
set_value(1000 + random(100));

}

query_save_flag() { return 1; }
clean_up() { return 0; }
