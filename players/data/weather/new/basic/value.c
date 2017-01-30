/*
    basic/value.c - value of an object
    Feb 1992 by marion@cs.tu-berlin.de
*/

private int value;

void
set_value(int v) {
  if (v >= 0)
    value = v;
}

int
query_value() {
  return value;
}

int query_real_value() {  // Coogan 19-Nov-1998, moved from obj/weapon to here
  return value;
}

