#include "/players/eurale/closed/ansi.h"

int color;

reset(arg) {
  if (arg) return;
  call_out("trash_this", 100);
}

extra_look() {
if(color == "red")
  return HIR+capitalize(environment(this_object())->query_name())+
           " is covered with red paint"+NORM;
if(color == "yellow")
  return HIY+capitalize(environment(this_object())->query_name())+
           " is covered with yellow paint"+NORM;
if(color == "blue")
  return HIB+capitalize(environment(this_object())->query_name())+
           " is covered with blue paint"+NORM;
 if(color == "green")
   return HIG+capitalize(environment(this_object())->query_name())+
           " is covered with green paint"+NORM;
if(color == "white");
  return HIW+capitalize(environment(this_object())->query_name())+
           " is covered with white paint"+NORM;
}

trash_this() { destruct(this_object()); }

start_bucket_stuff(arg) { color = arg; }

drop() { return 1; }

id(str) { return str=="paint" || str=="color" || str=="pigment"; }
