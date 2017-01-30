#include <ansi.h>

id(str) {
  return str=="mark" || str=="mark of shame";
}

short(){
  return "The Mark of "+RED+"Shame"+NORM;
}

long(str){
  write("\
A blood-red mark cut deep into your body as a constant reminder as\n\
your failure as a Samurai.\n");
}

query_auto_load(){
  return basename(this_object())+":0";
}

drop(){
  return 1;
}