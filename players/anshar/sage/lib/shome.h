#include "/players/anshar/sage/def.h"

shome() {
  string current;
  current = TP->query_home();
  if(current == "/players/anshar/workroom.c") {
  write("You choose to log in at the Church.\n");
  TP->set_home("/room/church.c"); TP->save(); return 1; }
  write("You choose to log in at the "+BOLD+RED+"workroom\n"+NORM+NORM);
  TP->set_home("/players/anshar/workroom.c");
  TP->save(); return 1; }
