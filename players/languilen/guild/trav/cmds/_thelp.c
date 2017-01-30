#include "../guilddefs.h"
cmd_thelp(str){

  string doc, filename;

  if(!str) doc = "index";
  else doc = str;
  filename = GUILDDIR+"help/"+doc;
  if(file_size(filename) > 0) {
    write("   ---------- Traveler's help guide ----------  \n\n");
    cat(filename);
    write("   -------------------------------------------   \n");
  }
  else write("There is no help available for: "+str+".\n");
  return 1;
}

