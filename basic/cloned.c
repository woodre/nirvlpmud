/*
 * /basic/cloned.c
 *
 * Inherit this file and call cloned() in create() (or, reset() in 2.4.5)
 * to give the object a query_cloned function to query from what object
 * it has been cloned.
 */

private static string cloned_by;
private static string cloned_by_stack;

varargs static int cloned(string str) {
  if (str)
    cloned_by = str;
  else if (previous_object())
    cloned_by = object_name(previous_object());
  cloned_by_stack = implode(map(caller_stack(1), #'to_string),", ");
  return clonep();
}

string query_cloned() {
  return cloned_by;
}

string query_cloned_stack() {
  return cloned_by_stack;
}

