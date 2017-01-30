/*
 * a simple class providing functions for area sizes, Coogan, 13-Nov-2002
 *
 */

#pragma strong_types

private int area_size;

static string* query_persistent_variables() {
  return ({ "area_size" });
}

int query_area_size() {
  return area_size;
}

void set_area_size(int s) {
  area_size = s;
}

