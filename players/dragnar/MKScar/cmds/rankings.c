#include "../scar.h"
#include <ansi.h>

main() {
  int color;

  if (color = (int) previous_object()->query_ansi()) write(RED);
  write(pad("",40,'=')+"\n");
  if(color) write(CYA);
write("Champion of Mortal Kombat: ");
  if(color) write(HIW);
  write(RANK->Champion()+"\n");
  if(color) write(NORM+RED);
  write(pad("",40,'=')+"\n");
  if(color) write(NOSTYLE);
  write(RANK->list());
  if (color) write(RED);
  write(pad("",40,'=')+"\n");
  if (color) write(NOSTYLE);
  return 1;
}
