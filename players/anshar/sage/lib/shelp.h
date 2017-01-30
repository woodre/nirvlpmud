#include "/players/anshar/sage/def.h"

shelp(str) {
  write("\n");
  write(BOLD+RED+"\tMajor help needed...I have used Snow's stuff...\n"+NORM+NORM);
  if(!str) {
    cat("/players/anshar/sage/help/general.txt");
    write("\n"); return 1; }
  if(str == "advanced"){cat("/players/anshar/sage/help/advanced.txt"); return 1;}
  if(str == "rules"){cat("/players/anshar/sage/help/rules.txt"); return 1;}
 write("That help topic is not available.\n"); return 1; }
