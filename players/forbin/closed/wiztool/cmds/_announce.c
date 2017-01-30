#include "/players/forbin/ansi.h"
#include "/players/forbin/closed/wiztool/define.h"
#include "/players/forbin/closed/wiztool/funcs.h"

status main(string str) {
  if(!str) return 0;
  if(str == "history") {
    write((string)"/obj/user/chistory.c"->query_history("announce"));
    write("\n");
    return 1;
  } 
  if(str[0] == ':')
    emit_channel("announce", WTC+"("+HIW+randcase_letters("announce")+WTC+")"+NORM+" "+capitalize((string)this_player()->query_real_name())+" "+str[1..strlen(str)]+"\n");
  else
    emit_channel("announce", WTC+"("+HIW+randcase_letters("announce")+WTC+")"+NORM+" "+capitalize((string)this_player()->query_real_name())+" speaks: "+str+"\n");
  return 1;
}
