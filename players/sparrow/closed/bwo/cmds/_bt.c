#include "../defs.h"
cmd_bt(str) {
  object ob;
 if(!str) return 0;
  ob = OBJ+"chatob";
  if(str[0] == ':')
    ob->emote(str[1..strlen(str)-1]);
  else if(str=="history")
    write("/obj/user/chistory"->query_history("Black Willow Order"));
  else
    ob->tell(str+"\n");
  return 1; }
