/* Here are some simul_efuns for converting from LP312 to LDMud driver.
 * These existed as efuns on the 3.1.2 driver, but are no longer available
 * on LD.
 * Rumplemintz
 */

string file_name(object ob) {
  return object_name(ob);
}

varargs mapping allocate_mapping(int size, int width) {
  if (width)
    return m_allocate(size, width);
  else
    return m_allocate(size, 1);
}

varargs mixed *filter_array(mixed *arr, string fun, object ob, mixed extra) {
  return filter(arr, fun, ob, extra);
}

int file_size(string curr) {
  return file_size(curr);
}

string delete_spaces(string arg) {
  return (implode(explode(arg, " "), ""));
}
