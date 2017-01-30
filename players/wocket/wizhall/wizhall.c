#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/room.c";

reset(arg){
  if(arg) return;
  short_desc = "The Wizards' Hall";
  long_desc = "This is a hall.. for wizards.\n";
  set_light(1);

}
