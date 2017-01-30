#include "/players/feldegast/defines.h"

inherit "obj/container";

reset(arg) {
  ::reset();
  if(arg)return;
  name="box";
  short_desc="A gift box";
  long_desc="This is a box wrapped in bright sheets of colored paper, with a silk\nbow on top.\n";
  weight=1;
  set_can_open(1);
}
add_weight(x) {
  return 1;
}
can_put_and_get() {
  if(query_verb() && query_verb()=="put" && first_inventory(this_object())) return 0;
  return 1;
}
