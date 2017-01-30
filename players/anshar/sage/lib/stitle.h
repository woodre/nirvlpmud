#include "/players/anshar/hero/def.h"

stitle() {
  int lev;
  string str;
  lev = TP->query_level();
  if(lev > 19) { write("Set your own title.\n"); return 1; }
  lev += TP->query_extra_level();
  switch(lev) {
    case 1..40 : str = "the sage"; break;
  }
  TP->set_title(str);
  write("Title set.\n"); return 1; }

  
