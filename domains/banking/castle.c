#pragma strong_types

#include <banking.h>

void reset(status arg) {
  if (arg)
    return;
  load_object(BANKINGCASTLE); // this will load the V10 castle
}
