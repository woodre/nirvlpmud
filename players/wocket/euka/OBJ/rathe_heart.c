#include "/players/wocket/closed/ansi.h"

id(str){ return str == "heart" || str == "rathe heart"; }
short(){ return RED+"A rathe's heart"+OFF; }
long(){
  write("This is the "+RED+"heart"+OFF+" of a death rathe.\n");
}

query_weight(){ return 1; }
query_value(){ return 50; }
query_witch_value(){ return 1000+random(1000); }
get(){ return 1; }
drop(){ return 0; }
