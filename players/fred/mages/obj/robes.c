#include "/players/fred/mages/defs.h"
inherit "/obj/armor.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_ac(0);
  set_silently(1);
  set_id(ROBES);
  set_type(ROBES);
}

do_special(owner){
  if(owner->query_attack())
  if(!random(5)){
  return 1;
  }
}

init(){
  ::init();
  wear("mage_armor"); 
  }

drop(){ return 1; }

