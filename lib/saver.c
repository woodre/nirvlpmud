/*
 * lib/saver.c
 *
 * This library can be used to save one value into a given file or load
 * one value from a given file.
 *
 * You can use save() and load() in this library to save and load your data
 */

#pragma strong_types
#pragma no_clone
#pragma no_inherit

#include <kernel.h>

static variables inherit ACCESS;

mixed data;

void reset(int arg) {
  if (!arg)
    set_privilege(1);
}

void save(mixed m, string file) {
  data = m;
  save_object(file);
}

mixed load(string file) {
  data = 0;  // in case no file is to load...
  restore_object(file);
  return data;
}

