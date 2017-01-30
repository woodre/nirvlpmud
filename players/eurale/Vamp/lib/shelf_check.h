/*
  shelf_check.h
*/

#include "/players/eurale/defs.h"

/* -------- shelf: check the log file to see activity of <who> -------- */
shelf_check(str) {
  int i, item, shelf;
  string tmp, who, time, function;

if(TPGEXP < 672) return 0;

write("\nItems on the shelf for "+capitalize(str)+"\n");
  tmp = "x";
  while (tmp) {
    i++;
    tmp = read_file("/players/nooneelse/COFFIN_SHELF_LOG", i);
    if (tmp == "" || tmp == 0)
      tmp = 0;
    else {
      sscanf(tmp, "%s#%s#%s#%d#%d\n", who, time, function, item, shelf);
      if (who == str) write(time+"#"+function+"#"+item+"#"+shelf+"\n");
    }
  }
  return 1;
}
