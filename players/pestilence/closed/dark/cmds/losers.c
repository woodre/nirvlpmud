#include "/players/pestilence/ansi.h"

main(str) {
  write("\n");
  write(HIK+"\tDarkness flows from the ground surrounding you...\n"+NORM);
  if(!str) {
    cat("/players/pestilence/closed/dark/help/losers.txt");
    write("\n"); return 1; }
  write("Just type losers to see the scumbags that left this guild.\n"); return 1; }
