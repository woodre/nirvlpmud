#include "path.h"
inherit SQUARE;

reset() {
  name="Free Parking";
#ifdef FREE_PARKING
  long_desc="Collect "+MONEYSIGN+FREE_PARKING+" for landing here.\n";
#endif
}

#ifdef FREE_PARKING
land() {
  ::land();
  write("You get "+MONEYSIGN+FREE_PARKING+" for landing on free parking.\n");
  TPMOBJ->add_cash(FREE_PARKING);
}
#endif
