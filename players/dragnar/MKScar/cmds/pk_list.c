#include "../scar.h"
#include <ansi.h>

main() {
  int color;

  if (color = (int) previous_object()->query_ansi()) write(RED);
   write(pad("",30,'=')+"\n");
   if(color) write(CYA);
  write("Name:\t\tKills\n");
   if(color) write(RED);
   write(pad("",30,'=')+"\n");
   if(color) write(NOSTYLE);
  write(TOPLIST->list());
  if (color) write(RED);
   write(pad("",30,'=')+"\n");
   if (color) write(NOSTYLE);
  return 1;
}
