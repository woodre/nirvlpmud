#include "path.h"
inherit SQUARE;

reset() {
  name="Luxury Tax";
  long_desc="Pay "+MONEYSIGN+"75\n";
}

land() {
  ::land();
  write("You have to pay the luxury tax of "+MONEYSIGN+"75\n");
  TPMOBJ->add_cash(-75);
}
