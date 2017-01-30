#include "../../defs.h"
inherit "preserved";


query_bloodsoaked(){ return 1;}

id(str) {
  return str == "corpse" || str == "bloodsoaked corpse" || str == "bloodsoaked";
}

short() {
  if(!name) {
  set_name("an unknown victim"); }
  if(shortdesc)
  return shortdesc+" ("+HIR+"bloodsoaked"+OFF+")";
  return "corpse of "+name+" ("+HIR+"bloodsoaked"+OFF+")";
}

long() {
if(longdesc){
  write(longdesc);
  write("You can 'bury' this corpse if it is no longer wanted.\n");
  return;
}
write("The corpse of "+name+" is drenched in blood.  The skin has become loose \n"+
      "and malleable as it slides off the body.\n"+
      "The corpse is ready for harvesting.\n");
write("You can 'bury' this corpse if it is no longer wanted.\n");
}
