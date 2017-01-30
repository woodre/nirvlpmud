#include "/players/mythos/closed/play/m.h"

id(str) { return str == gemmer; }
init() {
  if(this_player()->query_level() < 200) destruct(this_object()); }
