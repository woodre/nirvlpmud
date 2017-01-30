#include "/players/mythos/closed/ansi.h"
inherit "room/room";

reset(arg){
  if(!arg){
    set_light(1);
    short_desc=RED+"CLOSED SPACE"+NORM;
    long_desc=
    "This is the holdings of Mythos....\n";


  }
}
