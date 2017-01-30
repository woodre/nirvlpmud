#include "../defs.h"
int main(string str){
  string verb, channel;
  channel=query_verb();
  if(!str||str=="history"||str=="list"||
   previous_object()->kspeech_off()||
    !this_player()->on_channel(channel))
    return 0;
  if(str[0] == ':' && strlen(str) > 1){
    str = str[1..strlen(str)-1];
    emit_channel(channel, "\
"+HIW+"("+NORM+channel+HIW+")"+NORM+" "+(string)this_player()->query_name()
+" "+str+"\n");
    return 1;
  }
  str = (string)"/players/x/guilds/knights/daemons/lang"->translate_sentence(str);
  switch(str[strlen(str)-1]) {
    case '!': verb = "exclaimeth"; break;
    case '?': verb = "asketh"; break;
    default: verb = "sayeth"; break;
  }
  emit_channel(channel, "\
("+HIW+channel+NORM+") "+(string)this_player()->query_name()
+" "+verb+", \""+str+"\"\n");
  return 1;
}
