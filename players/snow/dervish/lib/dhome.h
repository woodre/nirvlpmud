#include "/players/snow/dervish/def.h"

dhome() {
  string current;
  current = TP->query_home();
  if(current == "/players/snow/dervish/hall/hall.c") {
  write("You choose to log in at the Church.\n");
  TP->set_home("/room/church.c"); TP->save(); return 1; }
  write("You choose to log in at the "+BOLD+RED+"SandStorm\n"+OFF+OFF);
  TP->set_home("/players/snow/dervish/hall/hall.c");
  TP->save(); return 1; }
