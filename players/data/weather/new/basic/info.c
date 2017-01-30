/*
 * /basic/info.c -- Add extra information for Identify spells and the like.
 *
 * HISTORY
 *  Magor 12-Jul-1993 Created this file
 *  Alfe prepared it for closures 1997-Jan-24
 */

private mixed info_desc;

/*
 * void set_info(mixed str) -- set the info (string or closure)
 */
void set_info(mixed str) {
  info_desc = str;
}

/*
 * string query_info(void) -- query the info string
 */
string query_info() {
  return funcall(info_desc);
}
