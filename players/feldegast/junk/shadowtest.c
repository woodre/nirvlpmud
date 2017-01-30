#include "/players/feldegast/defines.h"
set_shadow(str) {
  object ob;
  ob=present(str,environment(TP));
  if(!ob) { write("No object to shadow.\n"); return 1; }
  if(!shadow(ob,1)) write("Shadow failed.\n");
}
query_name() { return "Shaft"; }
short() { return "The Paladin of the Night"; }
