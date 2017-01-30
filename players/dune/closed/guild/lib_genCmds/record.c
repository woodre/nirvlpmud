#include "../DEFS.h"

status main(string str) {
  if(!str) {
    write("What do you wish to record?\n");
    return 1; }
  write_file(LOGDIR + "/RECORD",
    "--------------------------------------------------\n"+
    "->"+TRN+"   ("+ctime()+")\n"+str+"\n");
  write("Your message will be added to the guild record.\n");
  return 1;
}
