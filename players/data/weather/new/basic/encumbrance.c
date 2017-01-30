/*
 * /basic/encumbrance.c by Alfe and Ugh for Tubmud 1997-May-28
 */

#include <encumbrance.h>

private mixed encumbrance;

void set_encumbrance(mixed enc) {
  encumbrance = enc;
}

int query_encumbrance() {
  return funcall(encumbrance);
}

int query_weight() {
  /* this is 245-weight * standard WEIGHT_FACTOR */
  return (query_encumbrance() + WEIGHT_FACTOR - 1) / WEIGHT_FACTOR;
}

void set_weight(int w) {     // Carador, Oct-1996
  set_encumbrance(w * WEIGHT_FACTOR);
}
