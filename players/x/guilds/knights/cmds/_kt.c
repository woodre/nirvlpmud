#include "../defs.h"

int main(string str){
  string verb;
  string msg;
  if(!str){
    write("Usage: 'kt <msg>'.\n"+
           "This will send a message on the Knight channel.\n");
    return 1;
  }
  if(str=="history" || str=="-h") {
    write("/obj/user/chistory"->query_history("KNIGHTS"));
     return 1;
  }
  if(str[0] == ':' && strlen(str) > 1){
    return (int)"/players/x/guilds/knights/cmds/_kte"->main(str[1..strlen(str)-1]);
  }
  str = (string)"/players/x/guilds/knights/daemons/lang"->translate_sentence(str);
  if(str[strlen(str)-1] == '?') verb = "asketh";
   else if(str[strlen(str)-1] == '!') verb = "exclaimeth";
  else verb = "sayeth";
  msg =("["+HIW+"-|--"+NORM+"Knights"+HIW+"--|-"+NORM+"] "+
    (string)this_player()->query_name()+" "+
     verb+", \""+str+"\"\n");
  CHANNEL->broadcast(msg+"\n");
  msg = "("+ctime()[11..15]+") "+msg;
  "/obj/user/chistory"->add_history("KNIGHTS", msg);
  return 1;
}
