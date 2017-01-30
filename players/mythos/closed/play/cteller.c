#include "/players/mythos/closed/ansi.h"

reset() {
  write_file("/players/mythos/closed/play/tell/DUH", "X\n");
}

get() { return 0; }
drop() { return 1; }
id(str) { return str == "ceeya"; }

catch_tell(str) {
  tell_object(find_player("mythos"),
  HIB+"ctell<<"+environment(this_object())->query_name()+">> "+NORM+str);
  return; }
