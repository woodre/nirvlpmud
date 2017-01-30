#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("board");
  set_alias("notice board");
  set_short("A notice board");
set_long(
"This is a board that displays those who have joined the guild\n"+
"and the person who let them in.\n"+
"To see the history you can 'read board'.\n");
  set_value(0);
  set_weight(200);
}
