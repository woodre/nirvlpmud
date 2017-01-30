#include "/players/pestilence/ansi.h"

main(str) {
  write("\n");
  write(HIK+"\tDarkness flows from the ground surrounding you...\n"+NORM);
  if(!str) {
    cat("/players/pestilence/closed/dark/log/combotell");
    write("\n"); return 1; }
  write("Just type pth.\n"); return 1; }
