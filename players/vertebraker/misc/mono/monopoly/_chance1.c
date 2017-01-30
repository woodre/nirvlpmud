#include "path.h"
inherit SQUARE;

reset() {
  name="Chance";
}

land() {
  ::land();
  CARDS->chance();
}
