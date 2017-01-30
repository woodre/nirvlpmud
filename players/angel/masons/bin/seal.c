#include "defs.h"

string *files;

status main(string str, int glevel) {
  if (!str) str = "help";

  if (!files)
    files = get_dir(DOCPATH+"*.txt");

  str += ".txt";
  if (member_array(str, files) < 0) {
    int i, siz;
    
    write("You can get help on the following subjects:\n");
    for (i = 0, siz = sizeof(files); i < siz; i++)
#ifndef __LDMUD__ /* Rumplemintz */
      write(files[i][0..-5]+"\n");
#else
      write(files[i][0..<5] + "\n");
#endif
    return 1;
  }

  cat(DOCPATH+str);
  return 1;
}
