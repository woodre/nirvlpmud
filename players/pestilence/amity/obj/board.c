#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("board");
  set_alias("notice board");
  set_short("A notice board");
set_long(
"This is a notice board that displays those who have killed the queen ant\n"+
"from the amity area.  All results are from after July 7, 2002.\n"+
"To see the results you can 'read board'.\n");
  set_value(0);
  set_weight(200);
}
