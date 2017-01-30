#include "std.h"
id(str) { return str == "bed"; }
short() { return "A soft, comfortable looking bed"; }
long() {
write("This is a soft, comfortable looking bed covered in a strange, fuzzy\n"+
"blanket with glowing with a soft blue aura.\n");
write("\nIt looks like someone has been sleeping on it until recently.\n"+
  "the sheets and covers are still warm.\n");
}

init() {
  add_action("lay","lay");
}

lay(str) {
  if(!str || str != "on bed") return 0;
  write("You would just love to do that, would'nt you?\n"+
  "Something tells you that it would not be a good idea for some reason.\n");
  return 1;
}
