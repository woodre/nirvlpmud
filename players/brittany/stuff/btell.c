#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "brittany";
  cap_owner = "Brittany";
  color = MAG;
  extra_look = "Brittany's sly smile reveals "+RED+"blood ridden"+OFF+" fangs";
}
