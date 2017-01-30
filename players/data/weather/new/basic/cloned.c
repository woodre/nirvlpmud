/*
 *    basic/cloned.c - query_cloned
 *   Jan 1992 by marion@cs.tu-berlin.de
 *
 *   Inherit this file and call cloned() in create() (or, reset() in 2.4.5)
 *   to give the object a query_cloned function to query from what object
 *   it has been cloned.
 */

// added modifier 'static'. i see no reason why this information should be
// stored in a .o-file in any case.  Alfe 1997-Aug-21
private static string cloned_by;
private static string cloned_by_stack;

varargs static int cloned(string str) {  // str added by Carador, Oct-1996
  if (str)
    cloned_by = str;
  else if (previous_object())
    cloned_by = object_name(previous_object());
  // added following line   Alfe 1997-Jun-26
  cloned_by_stack = implode(map(caller_stack(1),#'to_string),", ");
  return clonep();
}

string query_cloned() {
  return cloned_by;
}

string query_cloned_stack() {
  return cloned_by_stack;
}
