#include "path.h"
inherit SQUARE;

reset() {
  name="Income Tax";
  long_desc="Pay 10% or "+MONEYSIGN+"200\n";
}

land() {
  int tmp;

  ::land();

  tmp=TPMOBJ->query_worth()/10;
  if(tmp>200) tmp=200;
  write("You have to pay income tax ("+MONEYSIGN+tmp+")\n");
  TPMOBJ->add_cash(-tmp);
}

