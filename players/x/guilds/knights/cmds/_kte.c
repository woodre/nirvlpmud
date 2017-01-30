#include "../defs.h"
int main(string str){
  string msg;
  if(!str){
    write("Usage: 'kte <msg>'\n"+
         "This will send an emote on the Knight channel.\n");
    return 1;
  }
  msg =(HIW+"["+NORM+"-|--"+HIW+"Knights"+NORM+"--|-"+HIW+"] "+NORM+
     (string)this_player()->query_name()+" "+str+"\n");
  CHANNEL->broadcast(msg+"\n");
  msg = "("+ctime()[11..15]+") "+msg;
  "/obj/user/chistory"->add_history("KNIGHTS", msg);
  return 1;
}
