#include "../DEFS.h"

status main(string str) {
  string file;

  if (!call_other(OFFICED, "checkStone", TP, "diamond sapphire onyx")) return 0;
  if (!str)
  {
    write("You may access the following data logs.\n");
    ls(LOGDIR);
    write("(or specify 'AUTO' to see the special log)\n");
    return 1; 
  }
  if (str == "AUTO" || str == "auto") file = "/log/dune.auto";
  else                                file = LOGDIR +"/"+ str;
  if(file_size(file) >= 0)
  {
    write("You access the " + str + " data log.\n");
    call_other(MORED, "more_file", file);
    return 1; 
  }
  write("There is no " + str + " data log.\n");
  return 1; 
}
