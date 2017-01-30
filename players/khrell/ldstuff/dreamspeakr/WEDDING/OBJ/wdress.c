#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}


reset(arg) {
set_name("wedding_dress");
set_alias("dress");
set_short("A beautiful wedding dress");
set_long(
  "This long flowing wedding dress was made specially for the happy \n"+
  "bride for her wedding day with her beloved.  The train seems to go \n"+
  "on forever, small lace rose's compliment the low open cleavage of \n"+
  "this magnificent dress. \n");

set_ac(1);
set_type("armor");
set_weight(1);
set_value(50);
}
query_save_flag() { return 1; }
