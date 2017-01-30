#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("michael");
  set_alt_name("archangel");
  set_alias("angel");
  set_short(HIB+"The Arch angel Michael"+NORM);
  
}
