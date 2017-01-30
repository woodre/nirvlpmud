#include "/players/daranath/guild/power/consume.h"
id(str) { return str == "tester"; }

init() {
  add_action("consume","consume");
}

