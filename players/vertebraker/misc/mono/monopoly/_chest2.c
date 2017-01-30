#include "path.h"
inherit SQUARE;

reset() {
  name="Community Chest";
}
 
land() {
  ::land();
  CARDS->chest();
}

