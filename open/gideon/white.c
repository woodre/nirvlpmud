#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "gideon";
  cap_owner = "Gideon";
  color = BOLD+HIW;
}

query_auto_load() {
	return "/open/gideon/white.c:";
}

