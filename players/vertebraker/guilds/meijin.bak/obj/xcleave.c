/*
 * xenhance id object
 */

id(str) { return str == "xcleave"; }

drop() {
  destruct(this_object());
  return 1;
}

