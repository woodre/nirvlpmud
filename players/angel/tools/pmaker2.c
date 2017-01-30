#include <ansi.h>
#define PLAN "/players/angel/PLAN"

void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(PLAN, HIB+"<:|:|:|:|:|:|< Angel >:|:|:|:|:|:|:>\n"+NORM+NORM);
  write_file(PLAN, MAG+"Area: Gas City \nIn Game: "+HIB+"Wal-Mart\n"+NORM+NORM+"In Game: "+HIB+"School\n\n"+NORM+NORM);
  write_file(PLAN, MAG+"Current coding: "+MAG+"Town of Gas City"+NORM+NORM+" \nAdding land for sale in Gas City\n\n");
  write_file(PLAN, MAG+"Future Plans: "+HIB+"Create guild"+NORM+NORM+"\n");
  write_file(PLAN, HIB+"|<:|:|:|:|:|:|< Wizard >:|:|:|:|:|:|:>|\n"+NORM+NORM);
  destruct(this_object());
}