#include "/players/languilen/closed/ansi.h"
#define BANNER RED+"--------------------------->  "+HIW+"The Mob RULES!"+ \
          NORM+RED+"  <---------------------------"+NORM

mhelp_cmd(str) {
string doc, filename;
  if(!str) doc = "index";
  else doc = str;
  filename = GUILDDIR+"help/"+doc;
  if(file_size(filename) > 0) {
    write(REF+BANNER+"\n");
    cat(filename);
    write(BANNER+"\n");
  }
  else write("There is no help available on the topic: "+str+".\n");
  return 1;
}
