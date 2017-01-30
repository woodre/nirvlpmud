#include "/players/mythos/closed/guild/def.h"
string ti, pt, tr;
id(str) {return str == "form_ob"; }
		
get() {return 0; }
drop() {return 1;}

query_weight() {return 0;}
query_value() {return 0; }
set_ti(tt) { tr = tt;}

init() {
 /* help file */

  add_action("shelp","shape_help");
  add_action("nnot","nnot"); 
  add_action("normal","smn");
}

normal() {
  tp->set_title(ti);
  tp->set_pretitle(pt);
  tp->save_me();
  return 0;
}

shelp() {
  write("Note:  Remember, atmosphere and role playing is everything!\n"+
        "       If you are a snake- be a snake....:>\n"+
        "ALSO: If it is found that this ability of shape change is abused\n");
  write("      it will be taken out.                  -Mythos the Prophet\n");
return 1;}

nott() {
  pt=tp->query_pretitle();
  ti=tp->query_title();
  tp->set_title(NORM+GRN+"the "+tr+NORM);
  tp->set_pretitle(GRN+"<"+NORM+YEL+"()"+NORM+GRN+"> ");
}
