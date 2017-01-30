#include "/players/fred/mages/defs.h"

cmd_gemote(str){
 string peep;
 object *stuff, books;
 int x;
  string em, file, arg;
   if(!str) { write("Emote what?\n"); return 1; }
  if(sscanf(str, "%s %s", em, arg) != 2) {
    em = str;
  }
    em = implode(explode(em, "."), "");
  if(file_size(file="/bin/soul/_"+em+".c") > 0) {
    return (int)file->guildcast("black circle", arg);
  }
    stuff = users();
    str = format(str,60);
    peep = capitalize((string)TPRN);
     for(x=0; x<sizeof(stuff); x++) {
       books = present("dark_circle",stuff[x]);
       if(books){
       tell_object(stuff[x], YEL+
       "("+BOLD+"Circle"+NORM+YEL+") "+NORM+peep+" "+str);
       }
     }
  "/obj/user/chistory"->add_history("Circle",
  YEL+"("+BOLD+"Circle"+NORM+YEL+") "+NORM+peep+" "+str);
  return 1;
}
