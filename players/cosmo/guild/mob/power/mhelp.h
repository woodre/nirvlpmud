#include "/players/cosmo/closed/ansi.h"
#define BANNER RED+"--------------------------->  "+HIW+"The Mob RULES!"+ \
          NORM+RED+"  <---------------------------"+NORM

mhelp(str) {
string doc, filename;
  if(!str) doc = "index";
  else doc = str;
  filename = "/"+CDIR+"docs/help/"+doc;
  if(file_size(filename) > 0) {
    write(REF+BANNER+"\n");
    if(file_size(filename) > 1) cat(filename); else more(filename);
    write(BANNER+"\n");
  }
  else write("There is no help available on the topic: "+str+".\n");
  return 1;
}
