#include "../DEFS.h"
#define LEVEL  7

void showMasks();

status main(string str) {
  int i, num;
  string * masks;
  masks    = allocate(8);
  masks[0] = "white lord";
  masks[1] = "paladin";
  masks[2] = "crusader";
  masks[3] = "neutral";
  masks[4] = "evil";
  masks[5] = "infamous";
  masks[6] = "black knight";
  masks[7] = "lord of evil";

  if(!gotrank(TP, LEVEL)) return 0;
  if(!str) {
    write("You may mask yourself to one of the following alignments:\n");
    for(i=0; i < sizeof(masks); i++) write("\t["+BOLD+i+OFF+"]\t"+masks[i]+"\n");
    write("Usage: mask <number>\n");
    return 1;
  }
  sscanf(str, "%d", num);
  if(num < 0 || num > sizeof(masks)) {
    write("There is no such mask. Specify an index number:\n");
    for(i = 0; i < sizeof(masks); i++) write(i+":    "+masks[i]+"\n");
    return 1;
  }
  TP->set_al_title(masks[num]);
  write("You emit a hologram that masks your alignment to "+masks[num]+".\n");
  return 1;
}
