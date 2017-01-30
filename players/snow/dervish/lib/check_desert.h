#include "/players/snow/dervish/def.h"

check_desert(object ob) {
  object myenv;
  string sdesc, ldesc;
  if(!ob) return;
  if(myenv != environment(ob)) return;
  ldesc = myenv->query_long();
  sdesc = myenv->query_short();
  if(sscanf(ldesc, "%sdesert%s") || sscanf(ldesc, "desert%s") || sscanf(ldesc, "%sdesert") ||
      sscanf(ldesc, "%ssand%s") || sscanf(ldesc, "%ssand") || sscanf(ldesc, "sand%s") ||
      sscanf(sdesc, "%sdesert%s") || sscanf(sdesc, "%sdesert") || sscanf(sdesc, "desert%s") ||
      sscanf(sdesc, "%ssand%s") || sscanf(sdesc, "%ssand") || sscanf(sdesc, "sand%s") ) return 1;
  else return 0; }
