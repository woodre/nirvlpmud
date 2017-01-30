#include "/players/fred/mages/defs.h"

cmd_gchat(str){
 string peep;
 object *stuff, books;
 int x;
  if(!str) { write("Say what?\n"); return 1; }
  if(str == "history"){
    write("/obj/user/chistory"->query_history("Circle"));
    return 1; }
  stuff = users();
  str = format(str,60);
  peep = capitalize((string)TPRN);
     for(x=0; x<sizeof(stuff); x++) {
        books = present("dark_circle",stuff[x]);
        if(books){
        tell_object(stuff[x], YEL+
        "("+BOLD+"Circle"+NORM+YEL+") "+NORM+peep+": "+str);
      }
     }
  "/obj/user/chistory"->add_history("Circle",
   YEL+"("+BOLD+"Circle"+NORM+YEL+") "+NORM+peep+": "+str);
  return 1;
}
