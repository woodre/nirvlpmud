#include "../DEFS.h"

status main(string str) {
/* takes str and refers to files in doc directory */
  if(!str) {
    cat(DOCDIR+"/main_menu.txt");
    return 1; 
  }
  if(!call_other(MORED, "view_doc", str, DOCDIR))
    write("The database contains no such document.\n");
  return 1;
}